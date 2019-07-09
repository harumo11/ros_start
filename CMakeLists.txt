cmake_minimum_required(VERSION 3.10)

project(ros_start)

set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )

#roscpp.cmakeとstd_msgs.cmakeファイルを検索，取得
find_package(catkin REQUIRED COMPONENTS 
	roscpp 
	std_msgs
	)

# このパッケージが依存する他のパッケージがあったらここに記述
catkin_package(
	)

#ライブラリ本体の導入
include_directories(${catkin_INCLUDE_DIRS})

#コンパイル
add_executable(simple_subscriber src/simple_subscriber.cpp)
add_executable(simple_publisher  src/simple_publisher.cpp)
add_executable(using_class_method_subscriber src/using_class_method_subscriber.cpp)

#リンク
target_link_libraries(simple_subscriber ${catkin_LIBRARIES})
target_link_libraries(simple_publisher  ${catkin_LIBRARIES})
target_link_libraries(using_class_method_subscriber ${catkin_LIBRARIES})
