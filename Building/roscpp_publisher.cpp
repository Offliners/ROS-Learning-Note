#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "demo_topic_publisher");
	ros::NodeHandle node_obj;
	ros::Publisher number_publisher = node_obj.advertise<std_msgs::Int32>("/number", 10);
	ros::Rate loop_rate(10);

	int count = 0;
	while(ros::ok())
	{
		std_msgs::Int32 msg;
		msg.data = count;

		ROS_INFO("%d", msg.data);
		number_publisher.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		count++;
	}

	return 0;
}
