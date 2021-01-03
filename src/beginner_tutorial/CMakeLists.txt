cmake_minimum_required(VERSION 3.0.2)
project(beginner_tutorial)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  sensor_msgs
  std_msgs
  message_generation
  #beginner_tutorial
)

add_message_files(
	FILES
	steerAndVelocity.msg
	carPosition.msg
)
generate_messages(
	DEPENDENCIES
	std_msgs
)

catkin_package(
	CATKIN_DEPENDS roscpp std_msgs message_runtime	
)





include_directories(include ${catkin_INCLUDE_DIRS})



add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})

add_executable(talker_int src/talker_int.cpp)
target_link_libraries(talker_int ${catkin_LIBRARIES})

add_executable(listener_int src/listener_int.cpp)
target_link_libraries(listener_int ${catkin_LIBRARIES})

add_executable(talker_float src/talker_float.cpp)
target_link_libraries(talker_float ${catkin_LIBRARIES})

add_executable(listener_float src/listener_float.cpp)
target_link_libraries(listener_float ${catkin_LIBRARIES})

add_executable(talker_sin src/talker_sin.cpp)
target_link_libraries(talker_sin ${catkin_LIBRARIES})

add_executable(middle_event src/middle_event.cpp)
target_link_libraries(middle_event ${catkin_LIBRARIES})

add_executable(middle_timer src/middle_timer.cpp)
target_link_libraries(middle_timer ${catkin_LIBRARIES})

add_executable(talker_cos src/talker_cos.cpp)
target_link_libraries(talker_cos ${catkin_LIBRARIES})

add_executable(middle_sum src/middle_sum.cpp)
target_link_libraries(middle_sum ${catkin_LIBRARIES})


add_executable(speed src/speed.cpp)
target_link_libraries(speed ${catkin_LIBRARIES})

add_executable(x_y_theta_array src/x_y_theta_array.cpp)
target_link_libraries(x_y_theta_array ${catkin_LIBRARIES})

add_executable(view_point_x_y_theta_array src/view_point_x_y_theta_array.cpp)
target_link_libraries(view_point_x_y_theta_array ${catkin_LIBRARIES})

add_executable(target_x_y_array src/target_x_y_array.cpp)
target_link_libraries(target_x_y_array ${catkin_LIBRARIES})

add_executable(horizontal_diviation src/horizontal_diviation.cpp)
target_link_libraries(horizontal_diviation ${catkin_LIBRARIES})

add_executable(steering src/steering.cpp)
target_link_libraries(steering ${catkin_LIBRARIES})


add_executable(first_publisher src/first_publisher.cpp)
target_link_libraries(first_publisher ${catkin_LIBRARIES})

add_executable(kuroki src/kuroki.cpp)
add_dependencies(kuroki ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(kuroki ${catkin_LIBRARIES})

add_executable(posTalker src/posTalker.cpp)
add_dependencies(posTalker ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(posTalker ${catkin_LIBRARIES})
