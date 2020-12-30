#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include <std_msgs/Float32MultiArray.h>

ros::Publisher veiw_point_x_y_theta_array_pub;
std_msgs::Float32MultiArray veiw_point_x_y_theta_array;

float buf_for_speed = 0.0f;
const float Tp = 1.8f; //教科書p258参照。L=40m, V=80km/hを安定とみなし用いた

void speed_callback(const std_msgs::Float32::ConstPtr& speed){

  buf_for_speed = speed->data;
}

void x_y_theta_array_callback(const std_msgs::Float32MultiArray::ConstPtr& x_y_theta_array){
  veiw_point_x_y_theta_array.data.at(0) = x_y_theta_array->data.at(0)+buf_for_speed*Tp* cos(x_y_theta_array->data.at(2));
  veiw_point_x_y_theta_array.data.at(1) = x_y_theta_array->data.at(1)+buf_for_speed*Tp* sin(x_y_theta_array->data.at(2));
  veiw_point_x_y_theta_array.data.at(2) = x_y_theta_array->data.at(2);

  ROS_INFO("speed: [%.1f]  x_y_theta_array: [%.1f],[%.1f],[%.1f]  veiw_point_x_y_theta_array: [%.1f],[%.1f],[%.1f]", buf_for_speed, x_y_theta_array->data.at(0), x_y_theta_array->data.at(1), x_y_theta_array->data.at(2), veiw_point_x_y_theta_array.data.at(0), veiw_point_x_y_theta_array.data.at(1), veiw_point_x_y_theta_array.data.at(2));
  veiw_point_x_y_theta_array_pub.publish(veiw_point_x_y_theta_array);
}

int main(int argc, char **argv){

  ros::init(argc, argv, "forward_veiw_point");

  ros::NodeHandle n;
  veiw_point_x_y_theta_array.data.resize(3);
  veiw_point_x_y_theta_array_pub = n.advertise<std_msgs::Float32MultiArray>("view_point_x_y_theta_array", 3);
  ros::Subscriber speed_sub = n.subscribe("speed", 1000, speed_callback);
  ros::Subscriber x_y_theta_array_sub = n.subscribe("x_y_theta_array", 1000, x_y_theta_array_callback);

  ros::spin();

  return 0;
}