#include "ros/ros.h"
#include <std_msgs/Float32MultiArray.h>
#include <math.h>


ros::Publisher x_y_theta_array_pub;
std_msgs::Float32MultiArray x_y_theta_array;
int count = 0;

void timer_callback(const ros::TimerEvent& e){
    //車の軌道として、ほぼx軸に近いとみなせる緩やかなsinカーブを想定
    //車速が30km/hとして、約20秒進むごと1周期となるように、カーブの軌道の振動数を設定
    //カーブの軌道の振幅は1m
    ++count;
    x_y_theta_array.data.at(0) = 8.33f*0.025*(float)count;
    x_y_theta_array.data.at(1) = sin(6.28 * x_y_theta_array.data.at(0) / 166.6f);
    x_y_theta_array.data.at(2) = cos(6.28 * x_y_theta_array.data.at(0) / 166.6f);
    
    ROS_INFO("x: %.1f  y: %.1f  theta: %.1f", x_y_theta_array.data.at(0), x_y_theta_array.data.at(1), x_y_theta_array.data.at(2));
    x_y_theta_array_pub.publish(x_y_theta_array);
}

int main(int argc, char **argv){

  ros::init(argc, argv, "x_y_theta_array");

  ros::NodeHandle n;
  x_y_theta_array.data.resize(3);
  x_y_theta_array_pub = n.advertise<std_msgs::Float32MultiArray>("x_y_theta_array", 3);

  ros::Timer timer = n.createTimer(ros::Duration(0.025), timer_callback);
  ros::spin();

  return 0;
}