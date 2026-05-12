import rclpy 
from rclpy.node import Node 
from geometry_msgs.msg import TwistStamped

class Navigation(Node):
    def __init__(self):
        super().__init__("navigation")
        # create publishers
        self.speed_pub_ = self.create_publisher(TwistStamped, "cmd_vel", 10)
        # create timer
        self.timer = self.create_timer(0.1, self.loop)

    def loop(self):
        ''' Main node loop. '''
        self.set_speed(0.5, 0.1)
        
    def set_speed(self, linear: float, angular: float): 
        msg = TwistStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "base_link"
        msg.twist.linear.x = linear
        msg.twist.angular.z = angular
        self.speed_pub_.publish(msg)

def main(args=None):
    rclpy.init()
    node = Navigation()
    try: 
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass 
    finally: 
        node.destroy_node()
        rclpy.shutdown()
 
if __name__ == "__main__":
    main(args=None)