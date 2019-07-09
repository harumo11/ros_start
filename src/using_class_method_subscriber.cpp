#include <iostream>
#include <ros/ros.h>
#include <std_msgs/String.h>

class Listener {
	public:
		//valiable
		std::string receive_data;

		//function
		void call_back(const std_msgs::String::ConstPtr& msg);
};

void Listener::call_back(const std_msgs::String::ConstPtr& msg)
{
	this->receive_data = msg->data;
	ROS_INFO("Received data : %s", this->receive_data.c_str());
}

int main(int argc, char* argv[])
{
	ros::init(argc, argv, "listener_class");
	ros::NodeHandle node_handle;

	ros::Rate rate(1);

	Listener listener;
	ros::Subscriber sub = node_handle.subscribe("speek", 10, &Listener::call_back, &listener);

	while (ros::ok()) {
		ros::spinOnce();
		rate.sleep();
	}
	
	return 0;
}
