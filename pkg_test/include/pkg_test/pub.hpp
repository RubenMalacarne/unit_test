#ifndef PUB_HPP_
#define PUB_HPP_

#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace hello_world
{
class HelloWorldPublisher : public rclcpp::Node
{
public:
  HelloWorldPublisher();
  ~HelloWorldPublisher() override;

private:
  void timer_callback();
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
};
}

#endif // HELLO_WORLD_PUBLISHER_HPP_
