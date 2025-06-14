#include "pub.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<hello_world::HelloWorldPublisher>());
  rclcpp::shutdown();
  return 0;
}
