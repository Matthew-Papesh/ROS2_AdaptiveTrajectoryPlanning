import rclpy 
from rclpy.node import Node 
from std_msgs.msg import String 

class Navigation(Node):
    def __init__(self):
        super().__init__("navigation")
        self.publisher_ = self.create_publisher(String, "topic", 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.i=0

    def timer_callback(self):
        msg = String()
        msg.data = f"Node says: {self.i}"
        self.publisher_.publish(msg)
        self.get_logger().info(f"Publishing: {msg.data}")
        self.i += 1

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