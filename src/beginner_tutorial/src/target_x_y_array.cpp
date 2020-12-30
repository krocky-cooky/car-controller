#include "ros/ros.h"
#include <std_msgs/Float32MultiArray.h>
#include <math.h>


ros::Publisher target_x_y_array_pub;
std_msgs::Float32MultiArray target_x_y_array;
int count = 0;

void timer_callback(const ros::TimerEvent& e){
    //目標コースとしてx軸を想定
    ++count;
    target_x_y_array.data[0] = 8.33f*0.025*(float)count;
    target_x_y_array.data[1] = 0;
    
    ROS_INFO("x: %.1f  y: %.1f", target_x_y_array.data[0], target_x_y_array.data[1]);
    target_x_y_array_pub.publish(target_x_y_array);
}

int main(int argc, char **argv){

  ros::init(argc, argv, "target_x_y_array");

  ros::NodeHandle n;
  target_x_y_array.data.resize(3);
  target_x_y_array_pub = n.advertise<std_msgs::Float32MultiArray>("target_x_y_array", 2);

  ros::Timer timer = n.createTimer(ros::Duration(0.025), timer_callback);
  ros::spin();

  return 0;
}