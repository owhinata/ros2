
#include <memory>

#include "example_interfaces/srv/add_two_ints.hpp"
#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/add_three_ints.hpp"

void add(
    const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
    std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response) {
  response->sum = request->a + request->b;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
              "Incomming request\na: %ld"
              " b: %ld",
              request->a, request->b);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]",
              (long int)response->sum);
}

void add3(const std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Request>
              request,
          std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Response>
              response) {
  response->sum = request->a + request->b + request->c;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
              "Incomming request: a: %ld b: %ld c: %ld", request->a, request->b,
              request->c);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]",
              response->sum);
}

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  std::shared_ptr<rclcpp::Node> node =
      rclcpp::Node::make_shared("add_two_ints_server");
  rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service =
      node->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints",
                                                                &add);
  rclcpp::Service<tutorial_interfaces::srv::AddThreeInts>::SharedPtr service2 =
      node->create_service<tutorial_interfaces::srv::AddThreeInts>(
          "add_three_ints", &add3);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add two ints.");
  rclcpp::spin(node);
  rclcpp::shutdown();
}
