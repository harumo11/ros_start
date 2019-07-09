#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char* argv[])
{
    //ros node initialize
    ros::init(argc, argv, "simple_publisher_node");
    //make ros node handle
    ros::NodeHandle nodeHandle;
    //make publisher. NOTE use same topic name between Publisher and Subscriber
    ros::Publisher publisher = nodeHandle.advertise<std_msgs::String>("speek", 1);
    
    //make loop timer
    ros::Rate loopRate(10);

    //make counter
    int count = 0;

    while (ros::ok()) {
        //make message for publish
        std::stringstream sstream;
        count++;
        sstream << "hello subscriber" << count;
        std_msgs::String str;
        str.data = sstream.str();

        //publish
        publisher.publish(str);
        ROS_INFO("%s", str.data.c_str());

        loopRate.sleep();
    }
    
    return 0;
}
