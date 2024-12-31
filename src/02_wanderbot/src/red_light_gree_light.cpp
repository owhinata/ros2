
#include <chrono>
#include <functional>
#include <memory>

#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class RedLightGreenLight : public rclcpp::Node {
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
  geometry_msgs::msg::Twist vel_;
  rclcpp::Time change_time_;
  bool driving_forward_ = false;

 public:
  RedLightGreenLight() : Node("red_light_gree_light") {
    timer_ = create_wall_timer(
        10ms, std::bind(&RedLightGreenLight::timer_callback, this));
    cmd_vel_pub_ = create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 2);
    set_vel();
    change_time_ = now() + rclcpp::Duration(3s);
  }

 private:
  void timer_callback() {
    auto now = this->now();
    if (now > change_time_) {
      change_time_ = now + rclcpp::Duration(3s);
      driving_forward_ = !driving_forward_;
      set_vel(driving_forward_ ? 0.5 : 0.0);
    }
    cmd_vel_pub_->publish(vel_);
  }

  void set_vel(double lx = 0.0, double ly = 0.0, double lz = 0.0,
               double wx = 0.0, double wy = 0.0, double wz = 0.0) {
    vel_.linear.x = lx;
    vel_.linear.y = ly;
    vel_.linear.z = lz;
    vel_.angular.x = wx;
    vel_.angular.y = wy;
    vel_.angular.z = wz;
  }
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RedLightGreenLight>());
  rclcpp::shutdown();
  return 0;
}
