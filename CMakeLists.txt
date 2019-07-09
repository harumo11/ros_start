cmake_minimum_required(VERSION 3.10)

project(ros_start)

set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )

#roscpp.cmakeとstd_msgs.cmake,message_generationファイルを検索，取得
find_package(catkin REQUIRED COMPONENTS 
	roscpp 
	std_msgs
	message_generation
	)

# 自作messageおよび，serviceを利用するとき用
add_service_files(
	FILES
	AddTwoInts.srv
	)

generate_messages(DEPENDENCIES std_msgs)

# このパッケージが依存する他のパッケージがあったらここに記述
# catkin build用の全ての記述が終了してからこのコマンドを記述しなければならない
catkin_package()


#ライブラリ本体の導入
include_directories(${catkin_INCLUDE_DIRS})

#コンパイル
add_executable(simple_subscriber src/simple_subscriber.cpp)
add_executable(simple_publisher  src/simple_publisher.cpp)
add_executable(using_class_method_subscriber src/using_class_method_subscriber.cpp)
add_executable(add_two_ints_server src/add_two_ints_server.cpp)
add_executable(add_two_ints_client src/add_two_ints_client.cpp)

#リンク
target_link_libraries(simple_subscriber ${catkin_LIBRARIES})
target_link_libraries(simple_publisher  ${catkin_LIBRARIES})
target_link_libraries(using_class_method_subscriber ${catkin_LIBRARIES})
target_link_libraries(add_two_ints_server ${catkin_LIBRARIES})
target_link_libraries(add_two_ints_client ${catkin_LIBRARIES})
