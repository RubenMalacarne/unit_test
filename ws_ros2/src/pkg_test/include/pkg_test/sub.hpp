#ifndef SUB_HPP_
#define SUB_HPP_

#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace hello_world
{
class HelloWorldSubscriber : public rclcpp::Node
{
public:
  HelloWorldSubscriber();
  ~HelloWorldSubscriber() override;

private:
  void topic_callback(const std_msgs::msg::String::SharedPtr msg);
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};
}

#endif // HELLO_WORLD_SUBSCRIBER_HPP_
