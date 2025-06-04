#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class HelloWorldSubscriber(Node):
    def __init__(self):
        super().__init__('hello_world_python_subscriber')
        self.last_msg = None
        self.subscription = self.create_subscription(
            String,
            'hello_world_topic',
            self.listener_callback,
            10
        )
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.last_msg = msg.data
        self.get_logger().info(f'I heard: "{msg.data}"')


def main(args=None):
    rclpy.init(args=args)
    node = HelloWorldSubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
