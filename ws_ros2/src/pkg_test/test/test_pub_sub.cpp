#include <gtest/gtest.h>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include "pub.hpp"
#include "sub.hpp"

#include <memory>
#include <future>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

class HelloWorldTest : public ::testing::Test
{
protected:
  static void SetUpTestSuite()
  {
    rclcpp::init(0, nullptr);
  }

  static void TearDownTestSuite()
  {
    rclcpp::shutdown();
  }
};

TEST_F(HelloWorldTest, PublisherNodeCreation)
{
  auto publisher_node = std::make_shared<hello_world::HelloWorldPublisher>();
  ASSERT_NE(publisher_node, nullptr);
}

TEST_F(HelloWorldTest, SubscriberNodeCreation)
{
  auto subscriber_node = std::make_shared<hello_world::HelloWorldSubscriber>();
  ASSERT_NE(subscriber_node, nullptr);
}

TEST_F(HelloWorldTest, PublisherPublishesMessage)
{
  auto publisher_node = std::make_shared<hello_world::HelloWorldPublisher>();
  auto subscriber_node = rclcpp::Node::make_shared("test_subscriber");

  std::shared_ptr<std_msgs::msg::String> received_message;
  auto sub = subscriber_node->create_subscription<std_msgs::msg::String>(
    "hello_world_topic", 10,
    [&](const std_msgs::msg::String::SharedPtr msg)
    {
      received_message = msg;
    });

  auto start = std::chrono::steady_clock::now();
  while (!received_message && std::chrono::steady_clock::now() - start < 5s) {
    rclcpp::spin_some(publisher_node);
    rclcpp::spin_some(subscriber_node);
    std::this_thread::sleep_for(100ms);
  }

  ASSERT_NE(received_message, nullptr);
}

int main(int argc, char ** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


// se ci sono errori di formato controllare scrivendo a line di comando: ament_uncrustify --reformat
