#include "ros/ros.h"
#include "std_msgs/Float32.h"


ros::Publisher speed_pub;
std_msgs::Float32 speed;


void timer_callback(const ros::TimerEvent& e){
  
  speed.data = 8.33f; // 8.33m/s (30km/h)
  
  ROS_INFO("speed: %.1f", speed.data);
  speed_pub.publish(speed);
}

int main(int argc, char **argv){

  ros::init(argc, argv, "speed");

  ros::NodeHandle n;
  speed_pub = n.advertise<std_msgs::Float32>("speed", 1000);

  ros::Timer timer = n.createTimer(ros::Duration(0.025), timer_callback);
  ros::spin();

  return 0;
}