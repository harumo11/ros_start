#include <iostream>
#include <ros/ros.h>
#include <ros_start/AddTwoInts.h>

int main(int argc, char* argv[])
{
	ros::init(argc, argv, "add_two_ints_client");
	if (argc != 3){
		std::cout << "usage : add_two_ints_client X Y" << std::endl;
		return 1;
	}

	ros::NodeHandle nh;
	// 呼び出すサービスを名前で指定
	ros::ServiceClient client = nh.serviceClient<ros_start::AddTwoInts>("add_two_ints");

	// リクエストを作成
	ros_start::AddTwoInts srv;
	srv.request.a = atof(argv[1]);
	srv.request.b = atof(argv[2]);

	// リクエストを投げて，レスポンスを受け取る
	if (client.call(srv)){
		std::cout << "sum : " << srv.response.sum << std::endl;
	}
	else
	{
		std::cout << "Failed to call service add_tow_ints" << std::endl;
		return 1;
	}
	
	return 0;
}
