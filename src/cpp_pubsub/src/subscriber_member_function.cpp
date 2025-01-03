
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "tutorial_interfaces/msg/num.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node {
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
  rclcpp::Subscription<tutorial_interfaces::msg::Num>::SharedPtr subscription2_;

  void topic_callback(const std_msgs::msg::String& msg) const {
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
  }

  void topic2_callback(const tutorial_interfaces::msg::Num& msg) const {
    RCLCPP_INFO_STREAM(this->get_logger(), "I heard: '" << msg.num << "'");
  }

 public:
  MinimalSubscriber() : Node("minimal_subscriber") {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    subscription2_ = this->create_subscription<tutorial_interfaces::msg::Num>(
        "topic2", 10, std::bind(&MinimalSubscriber::topic2_callback, this, _1));
  }
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
