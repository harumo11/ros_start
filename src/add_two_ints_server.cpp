#include <iostream>
#include <ros/ros.h>
#include <ros_start/AddTwoInts.h>

bool add(ros_start::AddTwoInts::Request &req, ros_start::AddTwoInts::Response & res)
{
	res.sum = req.a + req.b;
	ROS_INFO_STREAM("request: x=" << req.a << " , y=" << req.b);
	ROS_INFO_STREAM("sending back response: " << res.sum);
	
	return true;
}

int main(int argc, char* argv[])
{
	ros::init(argc, argv, "add_two_ints_server");
	ros::NodeHandle nh;

	ros::ServiceServer service = nh.advertiseService("add_two_ints", add);
	ROS_INFO("Ready to add tow ints.");
	ros::spin();
	
	return 0;
}

