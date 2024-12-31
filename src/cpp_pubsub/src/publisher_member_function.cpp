
#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "tutorial_interfaces/msg/num.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node {
  rclcpp::TimerBase::SharedPtr timer_, timer2_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::Publisher<tutorial_interfaces::msg::Num>::SharedPtr publisher2_;
  size_t count_;

  void timer_callback() {
    auto message = std_msgs::msg::String();
    message.data = "Hello, world! " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }

  void timer2_callback() {
    auto message = tutorial_interfaces::msg::Num();
    message.num = this->count_;
    RCLCPP_INFO_STREAM(this->get_logger(),
                       "Publishing: '" << message.num << "'");
    publisher2_->publish(message);
  }

 public:
  MinimalPublisher() : Node("minimal_publisher"), count_(0) {
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    timer_ = this->create_wall_timer(
        500ms, std::bind(&MinimalPublisher::timer_callback, this));

    publisher2_ =
        this->create_publisher<tutorial_interfaces::msg::Num>("topic2", 10);
    timer2_ = this->create_wall_timer(
        1s, std::bind(&MinimalPublisher::timer2_callback, this));
  }
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
