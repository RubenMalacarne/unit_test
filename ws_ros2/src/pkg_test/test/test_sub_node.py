import threading
import time
import pytest
import rclpy
from std_msgs.msg import String
from pkg_test.sub_node import HelloWorldSubscriber





@pytest.fixture
def rclpy_init_shutdown():
    rclpy.init()
    yield
    rclpy.shutdown()


def test_hello_world_subscriber_output(rclpy_init_shutdown):
    node = HelloWorldSubscriber()

    # Start spinning the node in a thread
    thread = threading.Thread(target=rclpy.spin, args=(node,), daemon=True)
    thread.start()

    pub = node.create_publisher(String, 'hello_world_topic', 10)

    time.sleep(0.5)  # Give time for the subscription to be set up

    msg = String()
    msg.data = 'Hello from test!'
    pub.publish(msg)

    time.sleep(0.5)  # Give time to receive the message

    node.destroy_node()
    thread.join(timeout=1)

    assert node.last_msg == "Hello from test!", "Subscriber did not receive the expected message"
