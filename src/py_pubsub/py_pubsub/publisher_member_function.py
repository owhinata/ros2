import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from tutorial_interfaces.msg import Num


class MinimalPublisher(Node):
    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(String, 'topic', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.publisher2_ = self.create_publisher(Num, 'topic2', 10)
        self.i = 0

    def timer_callback(self):
        msg = String()
        msg.data = 'Hello World: %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        msg2 = Num()
        msg2.num = self.i + 10
        self.publisher2_.publish(msg2)
        self.get_logger().info('Publishing: "%d"' % msg2.num)
        self.i += 1


def main(args=None):
    rclpy.init(args=args)
    minimal_publisher = MinimalPublisher()
    rclpy.spin(minimal_publisher)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
