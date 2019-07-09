#include <iostream>
#include <sstream>
#include <ros/ros.h>
#include <std_msgs/String.h>

void callBack(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("%s",msg->data.c_str()); 
}

int main(int argc, char* argv[])
{
    //ros node initialis
    ros::init(argc, argv, "simple_subscriber_node");
    //make node handle
    ros::NodeHandle nodeHandle;
    //make subscriber
    ros::Subscriber subscriber = nodeHandle.subscribe("speek", 1, callBack);

    while (ros::ok()) {
        ros::spinOnce();
        //std::cout << count++ << std::endl;
    }



    
    return 0;
}
