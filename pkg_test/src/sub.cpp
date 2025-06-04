#include "sub.hpp"

#include <functional>

namespace hello_world
{
HelloWorldSubscriber::HelloWorldSubscriber()
: Node("hello_world_subscriber")
{
  subscription_ = this->create_subscription<std_msgs::msg::String>(
    "hello_world_topic", 10,
    std::bind(&HelloWorldSubscriber::topic_callback, this, std::placeholders::_1));
}

HelloWorldSubscriber::~HelloWorldSubscriber()
{
  RCLCPP_INFO(this->get_logger(), "Shutting down subscriber.");
}

void HelloWorldSubscriber::topic_callback(const std_msgs::msg::String::SharedPtr msg)
{
  RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
}
}
