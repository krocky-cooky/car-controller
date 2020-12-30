#include "ros/ros.h"
#include "std_msgs/Float32.h"


ros::Publisher chatter_pub;
std_msgs::Float32 msg;

int count = 0;

void timer_callback(const ros::TimerEvent& e){
  ++count;
  
  msg.data = sin(((float)count)*0.1f);
  
  ROS_INFO("publish: %.1f", msg.data);
  chatter_pub.publish(msg);
}

int main(int argc, char **argv){

  ros::init(argc, argv, "talker_sin");

  ros::NodeHandle n;
  chatter_pub = n.advertise<std_msgs::Float32>("chatter_float", 1000);

  ros::Timer timer = n.createTimer(ros::Duration(0.1), timer_callback);
  ros::spin();

  return 0;
}