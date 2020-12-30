#include "ros/ros.h"
#include "std_msgs/Int32.h"


ros::Publisher chatter_pub;
std_msgs::Int32 msg;

int count = 0;

void timer_callback(const ros::TimerEvent& e){
  ++count;
  
  msg.data = count;
  
  ROS_INFO("publish: %d", msg.data);
  chatter_pub.publish(msg);
}

int main(int argc, char **argv){

  ros::init(argc, argv, "talker_int");

  ros::NodeHandle n;
  chatter_pub = n.advertise<std_msgs::Int32>("chatter_int", 1000);

  ros::Timer timer = n.createTimer(ros::Duration(0.1), timer_callback);
  ros::spin();

  return 0;
}