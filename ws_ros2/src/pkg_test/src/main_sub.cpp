#include "sub.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<hello_world::HelloWorldSubscriber>());
  rclcpp::shutdown();
  return 0;
}
