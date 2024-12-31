#include <chrono>
#include <functional>
#include <rclcpp/rclcpp.hpp>
#include <string>

using namespace std::chrono_literals;

class MinimalParam : public rclcpp::Node {
  rclcpp::TimerBase::SharedPtr timer_;

 public:
  MinimalParam() : Node("minimal_param_node") {
    declare_parameter("my_parameter", "world");
    timer_ = create_wall_timer(
        1000ms, std::bind(&MinimalParam::timer_callback, this));
  }

  void timer_callback() {
    std::string my_param = get_parameter("my_parameter").as_string();
    RCLCPP_INFO(get_logger(), "Hello %s!", my_param.c_str());
    std::vector<rclcpp::Parameter> all_new_parameters{
        rclcpp::Parameter("my_parameter", "world")};
    set_parameters(all_new_parameters);
  }
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalParam>());
  rclcpp::shutdown();
  return 0;
}
