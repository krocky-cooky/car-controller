#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include <std_msgs/Float32MultiArray.h>
#include "beginner_tutorial/steerAndVelocity.h"
#include "beginner_tutorial/carPosition.h"


ros::Publisher veiw_point_x_y_theta_array_pub;
//std_msgs::Float32MultiArray veiw_point_x_y_theta_array;
beginner_tutorial::carPosition veiw_point_x_y_theta_array;

float buf_for_speed = 0.0f;
const float Tp = 1.8f; //教科書p258参照。L=40m, V=80km/hを安定とみなし用いた

void speed_callback(const std_msgs::Float32::ConstPtr& speed){

  buf_for_speed = speed->data;
}

void x_y_theta_array_callback(const beginner_tutorial::carPosition::ConstPtr& x_y_theta_array){
  veiw_point_x_y_theta_array.x = x_y_theta_array->x+buf_for_speed*Tp* cos(x_y_theta_array->yaw);
  veiw_point_x_y_theta_array.y = x_y_theta_array->y+buf_for_speed*Tp* sin(x_y_theta_array->yaw);
  veiw_point_x_y_theta_array.yaw = x_y_theta_array->yaw;

  ROS_INFO("speed: [%.1f]  x_y_theta_array: [%.1f],[%.1f],[%.1f]  veiw_point_x_y_theta_array: [%.1f],[%.1f],[%.1f]", buf_for_speed, x_y_theta_array->x, x_y_theta_array->y, x_y_theta_array->yaw, veiw_point_x_y_theta_array.x, veiw_point_x_y_theta_array.y, veiw_point_x_y_theta_array.yaw);
  veiw_point_x_y_theta_array_pub.publish(veiw_point_x_y_theta_array);
}

int main(int argc, char **argv){

  ros::init(argc, argv, "veiw_point_x_y_theta_array");

  ros::NodeHandle n;
  veiw_point_x_y_theta_array_pub = n.advertise<beginner_tutorial::carPosition>("view_point_x_y_theta_array",1000);
  ros::Subscriber x_y_theta_array_sub = n.subscribe("car_position", 1000, x_y_theta_array_callback);

  ros::spin();

  return 0;
}
