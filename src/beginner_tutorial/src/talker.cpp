#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

ros::Publisher chatter_pub;
std_msgs::String msg;

int count = 0;

void timer_callback(const ros::TimerEvent& e){
  ++count;
  
  std::stringstream ss;
  ss << "hello world " << count;
  msg.data = ss.str();
  
  ROS_INFO("publish: %s", msg.data.c_str());
  chatter_pub.publish(msg);
}

int main(int argc, char **argv){

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;
  chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Timer timer = n.createTimer(ros::Duration(0.1), timer_callback);
  ros::spin();

  return 0;
}