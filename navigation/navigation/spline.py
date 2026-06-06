#!/usr/bin/env python3
import matplotlib.pyplot as plt
import navigation.handler as handler
import math
import rclpy

from rclpy.node import Node
from navigation.quintic import Quintic
from navigation_interfaces.srv import Spline
from nav_msgs.msg import GridCells
from geometry_msgs.msg import PoseStamped

# plotting flags
RVIZ_PLOT_GRIDCELLS = True
MATPLOTLIB_PLOT_QUINTIC = False

class SplinePath(Node):
    """
    Represents a SplinePath ROS node that generates a spline path of interpolated waypoints.
    """
    def __init__(self):
        """
        Initializes a Spfrom rclpy.node import NodelinePath node.
        """
        super().__init__("spline_path")
        # matplotlib coordinate range: ((min_x, max_x), (min_y, max_y))
        self.plot_range = ((-4, 10), (-3, 10))

        # path data:
        self.path_x, self.path_y = None, None
        self.sd_steps, self.cumulative_sd_steps = None, None
        # publishers and subscribers:
        self.spline_gridcells_publisher = self.create_publisher(
            GridCells,
            "/spline_path/spline_gridcells", 
            10
        )
        # services 
        self.srv = self.create_service(
            Spline,
            "/spline_path/spline_plan",
            self.handle_spline_plan_service
        )
        # create timer 
        self.timer = self.create_timer(0.1, self.loop)
    
    def handle_spline_plan_service(self, request, response):
        """
        Represents the GetSplinePlan service for a simple spline path that expects a specified Path of waypoints 
        to constrain the spline path to. Returns the interpolated Path of points of the constrained spline. 
        """
        self.get_logger().info("QuinticSpline.py: GetSplinePlan service request heard")
        simple_path = request.waypoints_path
        spline_path_points = self.get_interpolated_spline(simple_path.poses)
        spline_path = handler.get_path((0, 0), 1.0, spline_path_points[0], spline_path_points[1])
        self.plot_gridcells(self.path_x, self.path_y, RVIZ_PLOT_GRIDCELLS)
        
        response.spline_path=spline_path 
        response.sd_steps=spline_path_points[2]
        response.cumulative_sd_steps=spline_path_points[3]
        return response

    def plot(self, path_x: list, path_y: list, plot: bool):
        if plot:
            # view interpolated quintic spline plot 
            plt.plot(path_x, path_y)
            plt.xlabel('X-axis')
            plt.ylabel('Y-axis')
            plt.title('Computed Quintic Spline Path')
            plt.xlim(self.plot_range[0][0], self.plot_range[0][1])
            plt.ylim(self.plot_range[1][0], self.plot_range[1][1])
            plt.axis("square")
            plt.grid(visible=True)
            plt.show()

    def plot_gridcells(self, path_x: list, path_y: list, plot: bool) :
        if plot:
            gridcells = handler.get_gridcells_by_list((0, 0), 1.0, path_x, path_y)
            gridcells.header.stamp = self.get_clock().now().to_msg()
            self.spline_gridcells_publisher.publish(gridcells)

    def get_interpolated_spline(self, waypoints: list[PoseStamped]) -> tuple[list, list, list, list]:
        # create subpoint lists
        path_x, path_y, sd_steps, cumulative_sd_steps = [], [], [], []
        # iterate between waypoints to generate quintic splines
        for p_index in range(1, len(waypoints)):
            p_0 = waypoints[p_index - 1]
            p_1 = waypoints[p_index]

            if p_index > 1:
                path_x.pop()
                path_y.pop()
                sd_steps.pop()
                cumulative_sd_steps.pop()

            # find relative frame of reference
            delta_x = p_1.pose.position.x - p_0.pose.position.x
            delta_y = p_1.pose.position.y - p_0.pose.position.y
            rel_x = delta_x*math.cos(-handler.get_heading(p_0)) - delta_y*math.sin(-handler.get_heading(p_0))
            rel_y = delta_x*math.sin(-handler.get_heading(p_0)) + delta_y*math.cos(-handler.get_heading(p_0))
            rel_theta = handler.get_heading(p_1) - handler.get_heading(p_0)
            # convert coords
            p_origin, p_rel = PoseStamped(), PoseStamped()
            p_rel.pose.position.x = rel_x
            p_rel.pose.position.y = rel_y
            p_rel.pose.orientation = handler.get_orientation(rel_theta)
            
            # compute the relative quintic spline function
            q = Quintic(p_origin, p_rel)
            q.set_obstacles([(1,0)], 0.75)
            q.optimize(epochs=100, k0=0.0, k1=0.0, T0=50, step_size=1)
            # the specified number of points to partition and interpolate
            partition_density = 50.0 
            euclid_distance = handler.euclid_distance((0.0, 0.0), (rel_x, rel_y))
            partitions = int(euclid_distance * partition_density)
            
            if partitions==0:
                continue # prevent div by zero
            
            # the amount to step by through x-domain when interpolating
            partition = rel_x / partitions
            # the initial arc distance for the current spline along the path; the spline created between two waypoints such that
            # the initial arc distance is the cumulative distance of the path traveled up until that point
            init_sd = 0 if len(cumulative_sd_steps) < 1 else cumulative_sd_steps[-1]

            # iterate through all partitions to compute the relative spline; 
            for b_index in range(0, partitions + 1):
                step_x = partition * b_index 
                sd = pow(1.0 + pow(q.dydx(step_x), 2.0), 0.5) * abs(partition)
                # Compute derivative to integrate arc distance between points as step size arc distance
                if b_index==0:
                    cumulative_sd = init_sd
                else:
                    cumulative_sd = sd + cumulative_sd_steps[-1]
                
                # rotate to global frame of reference about the origin with +p_0 heading, and translate to restore global spline
                x = step_x * math.cos(handler.get_heading(p_0)) - q.f(step_x) * math.sin(handler.get_heading(p_0)) + p_0.pose.position.x
                y = step_x * math.sin(handler.get_heading(p_0)) + q.f(step_x) * math.cos(handler.get_heading(p_0)) + p_0.pose.position.y
                # Append global path subpoints computed
                path_x.append(x)
                path_y.append(y)  
                sd_steps.append(sd)
                cumulative_sd_steps.append(cumulative_sd)
        self.path_x = path_x
        self.path_y = path_y
        self.sd_steps = sd_steps
        self.cumulative_sd_steps = cumulative_sd_steps
        return (path_x, path_y, sd_steps, cumulative_sd_steps)

    def loop(self):
        ''' Main node loop. '''
        if self.path_x is not None and self.path_y is not None:
            self.plot_gridcells(self.path_x, self.path_y, RVIZ_PLOT_GRIDCELLS)
            self.plot(self.path_x, self.path_y, MATPLOTLIB_PLOT_QUINTIC)
            self.path_x = None
            self.path_y = None

def main(args=None):
    rclpy.init()
    node = SplinePath()
    try: 
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass 
    finally: 
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main(args=None)