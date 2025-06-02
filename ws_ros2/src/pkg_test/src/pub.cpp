#include "pub.hpp"

#include <chrono>
#include <functional>
#include <string>

using namespace std::chrono_literals;

namespace hello_world
{
HelloWorldPublisher::HelloWorldPublisher()
: Node("hello_world_publisher"), count_(0)
{
  publisher_ = this->create_publisher<std_msgs::msg::String>("hello_world_topic", 10);
  timer_ = this->create_wall_timer(
    500ms, std::bind(&HelloWorldPublisher::timer_callback, this));     // Pubblica ogni 500ms
}

HelloWorldPublisher::~HelloWorldPublisher()
{
  RCLCPP_INFO(this->get_logger(), "Shutting down publisher.");
}

void HelloWorldPublisher::timer_callback()
{
  auto message = std_msgs::msg::String();
  message.data = "Hello, world! " + std::to_string(count_++);
  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
  publisher_->publish(message);
}
}
