#!/usr/bin/env python3
import rclpy 
from rclpy.node import Node 
from rclpy.qos import QoSProfile, ReliabilityPolicy
from geometry_msgs.msg import TwistStamped, PoseStamped
from nav_msgs.msg import Path, Odometry
from navigation_interfaces.srv import Spline
import navigation.handler as handler
import navigation.PID as PID
import math

class Navigator(Node):
    def __init__(self):
        super().__init__("navigator")
        self.qos = QoSProfile(
            depth=10,
            reliability=ReliabilityPolicy.BEST_EFFORT
        )
        # navigation way points:
        self.waypoints = [(2,1,0), (3,1.5,math.pi/4),(3.5,3.5,math.pi/2),(2.5,4.5,math.pi*3.0/4.0),(1,5,math.pi)]
        # create publishers
        self.speed_pub_ = self.create_publisher(TwistStamped, "cmd_vel", 10)
        # create subscribers 
        self.odom_sub_ = self.create_subscription(Odometry, "/odom", self.odom_callback, self.qos)
        # create timer
        self.timer = self.create_timer(0.1, self.loop)
        # create service clients 
        self.spline_called = False
        self.spline_srv = self.create_client(
            Spline,
            "/spline_path/spline_plan"
        )

        # class fields 
        self.curr_position = handler.get_pose_stamped(0,0,0)
        
        # absolute maximum centripetal acceleration given simulation physics
        coeff_static_friction = 1.0
        centripetal_acceleration = coeff_static_friction * 9.81 # [m/sec^2]
        # percentage of centripetal acceleration to consider when specifying max centripetal acceleration for spline path driving
        scaler = 0.8
        
        # motion profiling criteria:
        self.MAX_CENTRIPETAL_ACCELERATION = centripetal_acceleration * scaler # [m/sec^2]
        self.ACCELERATION = 0.1 # [m/sec^2]
        self.MAX_ANGULAR_SPEED = 0.4 # [radians/sec]
        self.MAX_LINEAR_SPEED = 1.5 # [m/sec]
        # other robot constraints: 
        self.MAX_SPLINE_TURN = 0.5 * math.pi # [radians]; the max amount the robot should turn when driving a spline
        self.TURTLEBOT3_RADIUS = 0.105 # [m]
        # pid feedback coefficients (linear and angular differential speed PID)
        self.ANG_KP, self.ANG_KI, self.ANG_KD = 15.152344, 0.000083, 15.357032
        self.LIN_KP, self.LIN_KI, self.LIN_KD = 1.050781, 0.002802, 1.097656

        # spline srv responses 
        self.spline_path, self.sd_steps, self.cumulative_sd_steps = None, [], []
        # stall for srv
        while not self.spline_srv.wait_for_service(timeout_sec=10):
            self.get_logger().info("Waiting for spline service")

    def odom_callback(self, msg):
        """
        Callback function as subscribed odometry listener
        """
        heading = handler.get_heading(msg.pose.pose.orientation)
        
        self.curr_position.pose.position.x = float(msg.pose.pose.position.x)
        self.curr_position.pose.position.y = float(msg.pose.pose.position.y)
        self.curr_position.pose.orientation = handler.get_orientation(heading)
        self.curr_position.header.frame_id = str(msg.header.frame_id)
        self.get_logger().info(f"updated odom: [{handler.get_heading(msg.pose.pose.orientation)}]")

    def loop(self):
        ''' Main node loop. '''
        self.set_speed(0,0)
        if self.spline_path == None and not self.spline_called:
            # add initial robot position to the front of the waypoints and request interpolated spline path. 
            temp_waypoints = [(self.curr_position.pose.position.x, self.curr_position.pose.position.y, handler.get_heading(self.curr_position))] + self.waypoints
            self.request_spline(waypoints=temp_waypoints)
        elif self.spline_path is not None: 
            self.get_logger().info(f"have spline!: odom=(x:{self.curr_position.pose.position.x}, y:{self.curr_position.pose.position.y}, head:{handler.get_heading(self.curr_position)})")
            recorded_path, recorded_speeds, ideal_speeds, x_errors, y_errors, heading_errors, lin_speeds, ang_speeds, lin_adjs, ang_adjs = self.drive_spline_path(self.waypoints, self.ACCELERATION, self.MAX_ANGULAR_SPEED, self.MAX_LINEAR_SPEED, self.MAX_CENTRIPETAL_ACCELERATION)
            self.reset_spline()
            # use spline here
    
    def request_spline(self, waypoints: list):
        """
        Requests a interpolated spline path of poses given specified waypoints. 
        :param waypoints [list] The specified PoseStamped list of poses to constraint a spline onto
        :returns a simple spline Path object
        """
        self.spline_called = True
        request = Spline.Request()
        simple_path = Path()

        for waypoint in waypoints:
            pose = PoseStamped()
            pose.pose.position.x = float(waypoint[0])
            pose.pose.position.y = float(waypoint[1])
            pose.pose.orientation = handler.get_orientation(float(waypoint[2]))
            simple_path.poses.append(pose)

        request.waypoints_path = simple_path
        future = self.spline_srv.call_async(request)
        future.add_done_callback(self.response_spline)

    def reset_spline(self):
        """
        Generate an interpolated spline path. 
        """
        self.spline_path = None 
        self.sd_steps = []
        self.cumulative_sd_steps = []

    def response_spline(self, future):
        """
        Retrieve service interpolated spline path
        """
        try: 
            response = future.result()
            self.get_logger().info("Spline path received!")
            self.spline_path = response.spline_path
            self.sd_steps = response.sd_steps
            self.cumulative_sd_steps = response.cumulative_sd_steps
        except Exception as e:
            self.get_logger().error(f"Service call failed: {e}")
        self.spline_called = False
        
    def set_speed(self, linear: float, angular: float): 
        """
        Published robot command velocity. 
        """
        msg = TwistStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "base_link"

        msg.twist.linear.x = float(linear)
        msg.twist.linear.y = 0.0
        msg.twist.linear.z = 0.0

        msg.twist.angular.z = float(angular)
        msg.twist.angular.x = 0.0
        msg.twist.angular.y = 0.0
        self.speed_pub_.publish(msg)

    def get_pose_index(self, spline_path: Path, pose: PoseStamped, kernel_index: int, padding: int) -> tuple[int]:
        """
        Calculates the pose index along a path that most closely approximates a specified pose. 
        :param path [Path] The specified path
        :param pose [PoseStamped] The specified pose to consider
        :param kernel_index [int] The specified position of the kernel or scope to evaluate 
        :param padding [int] The specified radius of the kernel or scope to evaluate
        :returns the most similar path position to that of the specified pose as an index
        """
        min_loss = None
        ideal_pose_index = 0
        for i in range(max(0, kernel_index - padding), min(kernel_index + padding + 1, len(spline_path.poses))):
            path_pose = spline_path.poses[i]
            x_loss = abs(path_pose.pose.position.x - pose.pose.position.x)
            y_loss = abs(path_pose.pose.position.y - pose.pose.position.y)
            loss = (x_loss + y_loss) / 2.0
            if min_loss is None or loss < min_loss:
                min_loss = loss
                ideal_pose_index = i
        return ideal_pose_index

    def get_path_speeds(self, spline_path: Path, sd_steps: list, cumulative_sd_steps: list, acceleration: float, max_linear_speed: float, max_angular_speed: float, max_centripetal_acceleration: float) -> tuple[list, list]:
        """
        Calculates speeds for each pose along a spline path. Linear and angular speeds are are determined given pose data while stepping through 
        the path to interpolate speeds knowing the specified acceleration. Pose data used come from the i-th pose along the spline, the i-th arc distance 
        between a pose and the previous on the spline from sd_steps, and the i-th arc distance between the initial position and the i-th pose from cumulative_sd_steps.
        Motion profiling criteria are taken into account as well. The following being the criteria of linear acceleration [m/sec^2], max linear speed [m/sec], 
        max angular speed [radians/sec], and max centripetal acceleration [m/sec^2]; motion criteria clamps speeds within absolution boundaries between zero and 
        the maximums specified and only changes speeds by the rate of acceleration specified. Finally, speeds are return in the form of a tuple of linear and angular 
        speeds of the same length and corresponding MSE order of the spline path specified. 

        :param spline_path [Path] The specified spline path to profile speeds for
        :param sd_steps [list] The specified list of float arc distances between a given pose and the previous on a spline path
        :param cumulative_sd_steps [list] The specified list of float cumulative arc distances between a given pose and the starting position of a spline path
        :param acceleration [float] The specified magnitude of acceleration in [m/sec^2] to profile by
        :param max_linear_speed [float] The specified max magnitude of tangential speed in [m/sec] to profile by
        :param max_angular_speed [float] The specified max magnitude of angular speed in [radians/sec] to profile by
        :param max_centripetal_acceleration [float] The specified max magnitude of centripetal acceleration in [m/sec^2] to profile by
        :returns a tuple of linear speeds and angular speeds respectively in the same corresponding order as the spline path specified 
        """
        tolerance = 1 # how much reach +/- the index to select other points for approximating a spline circle
        base_index = tolerance 
        acceleration = max(0.00001, abs(acceleration)) 
        # computed speeds
        linear_speeds = []
        angular_speeds = []
        deccelerate = False
        # iterate through spline waypoints to compute speeds
        for index in range(0, len(spline_path.poses)):
            # scroll tolerance range while iterating
            if index > base_index and index <= len(spline_path.poses) - tolerance - 1:
                base_index = index
            # compute instantaneous circle approximating continuous spline at given point
            p0, p1, p2 = spline_path.poses[base_index - tolerance], spline_path.poses[base_index], spline_path.poses[base_index + tolerance]
            (x_ICC, y_ICC, R) = handler.get_circle((p0.pose.position.x, p0.pose.position.y), (p1.pose.position.x, p1.pose.position.y), (p2.pose.position.x, p2.pose.position.y))
            
            # determine initial velocity (v_0) and arc distance (sd) coming from previous waypoint to the current
            v_0 = 0 if index == 0 else linear_speeds[len(linear_speeds) - 1]
            sd = sd_steps[index]
            # determine the direction (sign of angular speed (w_sgn)) of which the robot will turn
            delta_theta = handler.get_heading(p2) - handler.get_heading(p0)
            w_sgn = delta_theta / handler.non_zero(abs(delta_theta), 0.00001)
            # compute current waypoint's linear and angular velocity by kinematics
            v_1 = pow(abs(pow(v_0, 2.0) + 2.0*sd*acceleration), 0.5)
            w_1 = v_1 / handler.non_zero(abs(R), 0.00001) * w_sgn
            # compute centripetal acceleration (a_c) and decceleration distance
            a_c = pow(v_1, 2.0) / handler.non_zero(abs(R), 0.00001)
            deccel_distance = abs(-pow(v_1, 2.0) / (2.0 * acceleration))
            # check to deccelerate or not: check if remaining spline distance is longer than the distance needed to deccelerate
            remaining_distance = abs(cumulative_sd_steps[len(cumulative_sd_steps) - 1] - cumulative_sd_steps[index])
            remaining_distance = remaining_distance if remaining_distance > 0.05 else 0
            if not deccelerate and remaining_distance <= deccel_distance:
                # if just flagged True, the robot must of just noticed its speed, or any faster, would require slowing now to not overshoot the
                # end of the spline. Once deccelerating, the robot should not wait to slow or ever go faster; don't consider handling those cases.
                deccelerate = True
                acceleration = -abs(acceleration)
            if abs(a_c) > abs(max_centripetal_acceleration):
                # the robot must of just met/passed the max centripetal acceleration threshold; do not accelerate here but hold constant speed at the max linear speed.
                w_1 = v_0 / handler.non_zero(abs(R), 0.00001) * w_sgn
                v_1 = v_0
            elif abs(w_1) > abs(max_angular_speed):
                # the robot must of just met/passed the max angular speed threshold; do not accelerate here but hold constant speed at the max angular speed.
                w_1 = max_angular_speed * w_sgn
                v_1 = max_angular_speed * R
            elif abs(v_1) > abs(max_linear_speed):
                # the robot must of just met/passed the max linear speed threshold; do not accelerate here but hold constant speed at the max linear speed. 
                w_1 = max_linear_speed / handler.non_zero(abs(R), 0.00001) * w_sgn
                v_1 = max_linear_speed
            elif deccelerate and remaining_distance > deccel_distance:
                # if the robot is slowing down to soon stop but find the stop may come too early, then hold speeds constants
                w_1 = v_0 / handler.non_zero(abs(R), 0.00001) * w_sgn
                v_1 = v_0
            # add speeds
            linear_speeds.append(v_1)
            angular_speeds.append(w_1)
    
        return (linear_speeds, angular_speeds)

    def spline_drive(self, spline_path: Path, spline_sd_steps: list, spline_cumulative_sd_steps: list, acceleration: float, max_linear_speed: float, max_angular_speed: float, max_centripetal_acceleration: float) -> tuple[Path, list, list, list, list, list, list, list, list, list]:
        """
        Motion profiles and drives wheels speeds along a specified spline path given path poses, path arc distances, along with specified acceleration [m/sec^2], max linear speed [m/sec],
        max angular speed [radians/sec], and max centripetal acceleration [m/sec^2]. 
        :param spline_path [Path] The specified spline path of interpolated poses
        :param spline_sd_steps [list] The specified list of float arc distances between a given spline path pose and the previous. 
        :param spline_cumulative_sd_steps [list] The specified list of float cumulative arc distances between a given spline path pose and the starting position. 
        :param acceleration [float] The specified acceleration in [m/sec^2] to profile by
        :param max_linear_speed [float] The specified max linear speed in [m/sec] to profile by
        :param max_angular_speed [float] The specified max angular speed in [radians/sec] to profile by
        :param max_centripetal_acceleration [float] The specified max centripetal acceleration in [m/sec^2] to profile by
        """
        
        # current index point considered from a set of points about a base point on a spline path with a radius range of padding
        index, padding = 0, 10
        # feedback control offset from the current index to target when applying PID feedback systems
        feedback_target_offset = 3

        # create angular speed pid feedback handler based on the current index point along a spline
        def feedback_process_variable() -> float:
            orig_x = self.curr_position.pose.position.x
            orig_y = self.curr_position.pose.position.y
            orig_radians = handler.get_heading(self.curr_position)
            
            spline_x = spline_path.poses[min(index + feedback_target_offset, len(spline_path.poses) - 1)].pose.position.x
            spline_y = spline_path.poses[min(index + feedback_target_offset, len(spline_path.poses) - 1)].pose.position.y
            
            variable = handler.rotate(spline_x - orig_x, spline_y - orig_y, -orig_radians)[1]
            return variable

        # compute wheel speeds
        speeds = self.get_path_speeds(spline_path, spline_sd_steps, spline_cumulative_sd_steps, acceleration, max_linear_speed, max_angular_speed, max_centripetal_acceleration)
        linear_speeds, angular_speeds = speeds[0], speeds[1]
        # pid angular speed feedback controller 
        angular_speed_feedback = PID.PID(kp=self.ANG_KP, ki=self.ANG_KI, kd=self.ANG_KD, process_variable=feedback_process_variable, set_point=lambda: 0.0, clegg_integration=True)
        linear_speed_feedback = PID.PID(kp=self.LIN_KP, ki=self.LIN_KI, kd=self.LIN_KD, process_variable=feedback_process_variable, set_point=lambda: 0.0, clegg_integration=True)

        # path of odometry poses recorded to have minimal error with respect to their corresponding spline path waypoint
        recorded_path = Path()
        # list of 2D tuples of linear and angular speeds at recorded points along driven path
        recorded_speeds = []
        # list of 2D tuples of ideal linear and angular speeds; the recorded speeds are likely to slightly differ
        ideal_speeds = []
        # specified max time allowed to drive from one waypoint to the next before assuming that driving has failed
        frontier_timeout = 10
        # previous stamped time of reaching the next waypoint while driving
        prev_frontier_update_time = -1.0

        # min errors and associated recorded odometry pose compared-to/of a given waypoint 
        # such that the frontier is the current furthest point reached on the spline while driving
        min_position_error, min_heading_error, recorded_pose, frontier_index = None, None, None, -1
        # record the errors and resulting adjustments 
        recorded_x_error, recorded_y_error, recorded_heading_error = [], [], []
        recorded_lin_speeds, recorded_ang_speeds = [], []
        recorded_lin_adjs, recorded_ang_adjs = [], []
       
        # drive robot with speed data and feedback control
        while index < len(spline_path.poses) - 1:

            # approximate current position (current position; not recorded approximates to waypoints)
            index = self.get_pose_index(spline_path, self.curr_position, index, padding) 
            self.get_logger().info(f"curr pose: {self.curr_position.pose.position}")
            # current position error as a vector magnitude at any time
            raw_x_error = (self.curr_position.pose.position.x - spline_path.poses[index].pose.position.x)
            raw_y_error = (self.curr_position.pose.position.y - spline_path.poses[index].pose.position.y)
            raw_heading = 0# abs((handler.get_heading(self.curr_position) - handler.get_heading(spline_path.poses[index])) / self.MAX_SPLINE_TURN)
            position_x_pct_error = raw_x_error / (2.0 * self.TURTLEBOT3_RADIUS)
            position_y_pct_error = raw_y_error / (2.0 * self.TURTLEBOT3_RADIUS)
            position_error = handler.euclid_distance((0,0), (position_x_pct_error, position_y_pct_error))
            
            # check if the robot is taking too long to progress along the path; end path driving if progression/expanding the frontier driven takes too long
            # provided the robot has driven a "sufficient" distance from the starting point; let the sufficient distance be the padding used for approximating current position
            if index > padding and prev_frontier_update_time > 0 and self.get_clock().now() - prev_frontier_update_time > frontier_timeout:
                self.set_speed(0, 0) # stop driving, end early, and return pct performance errors of 100% to indicate faulty path driving
                return (recorded_path, recorded_speeds, ideal_speeds, None, None, None, None, None)

            # record the closest the robot drove to the point and compute error/best init pose of next point
            # if frontier expanded
            if index > frontier_index:
                if recorded_pose is not None: 
                    recorded_path.poses.append(handler.get_pose_stamped(recorded_pose.pose.position.x, recorded_pose.pose.position.y, handler.get_heading(recorded_pose)))
                    recorded_speeds.append((self.current_speed.linear.x, self.current_speed.angular.z))
                    ideal_speeds.append((linear_speeds[index], angular_speeds[index]))
                    # heading error associated with min error (position error) 
                    min_heading_error = abs((handler.get_heading(recorded_pose) - handler.get_heading(spline_path.poses[index])) / self.MAX_SPLINE_TURN)
                    raw_heading = min_heading_error

                prev_frontier_update_time = self.get_clock().now() # stamp time of updating frontier
                #min_position_error = position_error
                recorded_pose = self.curr_position
                frontier_index = index

                if min_heading_error is not None:
                    # record best case error (at this waypoint)
                    recorded_x_error.append(raw_x_error)
                    recorded_y_error.append(raw_y_error)
                    recorded_heading_error.append(min_heading_error)
                    recorded_lin_speeds.append(linear_speeds[index])
                    recorded_ang_speeds.append(angular_speeds[index])
                    # record best case speed adjustments 
                    recorded_lin_adjs.append(abs(linear_speed_feedback.output()))
                    recorded_ang_adjs.append(angular_speed_feedback.output())
                # reset to None for next waypoint
                min_position_error = None
                
             # evaluate the closest the robot drove by min error for current point
            elif min_position_error is None or position_error < min_position_error:
                min_position_error = position_error
                recorded_pose = self.curr_position

            # *** THIS IS THE ROBOT RUNNING SPEEDS AT RUNTIME ***
            # visualize padded local around the robot; visualize by gridcells
            #self.rvizViewSplinePathProgression(spline_path, index, padding)
            # look up memoized speed calculations given position index and system feedback control
            ang_speed = angular_speeds[index] + angular_speed_feedback.output() 
            #self.get_logger().info(f"set lin: {linear_speeds[index]}, index: {index}")
            lin_speed = max(0.001, abs(linear_speeds[index]) - max(0, abs(linear_speed_feedback.output())))
            self.set_speed(lin_speed, ang_speed) # SETTING ADJUSTED SPEEDS

        # come to a stop and return data
        self._speed(0, 0)
        return (recorded_path, recorded_speeds, ideal_speeds, recorded_x_error, recorded_y_error, recorded_heading_error, recorded_lin_speeds, recorded_ang_speeds, recorded_lin_adjs, recorded_ang_adjs)

    def drive_spline_path(self, waypoints: list, acceleration: float, max_linear_speed: float, max_angular_speed: float, max_centripetal_acceleration: float) -> tuple[Path, list, list, list, list, list, list, list]:
        """
        Drives a path of splines given waypoints to constrain the spline onto with motion profiling constraints of acceleration [m/sec^2], 
        max linear speed [m/sec], max angular speed [radians/sec], and max centripetal acceleration [m/sec^2]. The recorded path is returned alongside
        percent errors for position and heading.

        :param waypoints [list] The specified list of pose vectors for each waypoint of which the spline path should intersect through
        :param acceleration [float] The specified acceleration in [m/sec^2] to profile by
        :param max_linear_speed [float] The specified max linear speed in [m/sec] to profile by
        :param max_angular_speed [float] The specified max angular speed in [radians/sec] to profile by
        :param max_centripetal_acceleration [float] The specified max centripetal acceleration in [m/sec^2] to profile by

        :returns a tuple of recorded path of how close the robot got to each waypoint, speeds measured over the recorded path, computed ideal speeds, along with pct error for position (x,y) and heading in radians, and associated lin speed and ang speed adjustments 
        """
        # drive spline given computed spline path and motion profiling constraints. 
        recorded_path, recorded_speeds, ideal_speeds, x_errors, y_errors, heading_errors, lin_speeds, ang_speeds, lin_adjs, ang_adjs = self.spline_drive(
            self.spline_path, 
            self.sd_steps, 
            self.cumulative_sd_steps, 
            acceleration, 
            max_linear_speed, 
            max_angular_speed, 
            max_centripetal_acceleration
        )
        return (recorded_path, recorded_speeds, ideal_speeds, x_errors, y_errors, heading_errors, lin_speeds, ang_speeds, lin_adjs, ang_adjs)


def main(args=None):
    rclpy.init()
    node = Navigator()
    try: 
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass 
    finally: 
        node.destroy_node()
        rclpy.shutdown()
 
if __name__ == "__main__":
    main(args=None)