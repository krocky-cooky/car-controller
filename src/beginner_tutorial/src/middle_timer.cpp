#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"

ros::Publisher chatter_pub;
std_msgs::Float32 float_msg;
float buf;

void chatterCallback(const std_msgs::Int32::ConstPtr& rcv_msg){
  buf = ((float)rcv_msg->data)*0.1f;
}

void timer_callback(const ros::TimerEvent& e){  
  float_msg.data = buf;
  
  ROS_INFO("publish: %.1f", float_msg.data);
  chatter_pub.publish(float_msg);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "middle_event");

  ros::NodeHandle n;
  chatter_pub = n.advertise<std_msgs::Float32>("chatter_float", 1000);

  ros::Subscriber sub = n.subscribe("chatter_int", 1000, chatterCallback);
  ros::Timer timer = n.createTimer(ros::Duration(1.0), timer_callback);

  ros::spin();

  return 0;
}