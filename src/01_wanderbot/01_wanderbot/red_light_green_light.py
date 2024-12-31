import rclpy
from rclpy.node import Node
from rclpy.duration import Duration
from geometry_msgs.msg import Twist


class RedLightGreenLight(Node):
    def __init__(self):
        super().__init__('red_light_green_light')
        self.timer = self.create_timer(0.01, self.timer_callback)
        self.cmd_vel_pub = self.create_publisher(Twist, 'cmd_vel', 2)
        self.vel = Twist()
        self.driving_forward = False
        self.change_time = self.get_clock().now() + Duration(seconds=3)

    def timer_callback(self):
        now = self.get_clock().now()
        if now > self.change_time:
            self.driving_forward = not self.driving_forward
            self.change_time = now + Duration(seconds=3)
            if self.driving_forward:
                self.set_vel(0.5, 0.0)
            else:
                self.set_vel(0.0, 0.0)
        self.cmd_vel_pub.publish(self.vel)

    def set_vel(self, linear, angular):
        self.vel.linear.x = linear
        self.vel.angular.z = angular


def main(args=None):
    rclpy.init(args=args)
    node = RedLightGreenLight()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destory_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
