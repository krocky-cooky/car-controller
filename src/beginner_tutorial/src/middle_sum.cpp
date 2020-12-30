#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"

ros::Publisher chatter_pub;
std_msgs::Float32 float_msg;

float buf = 0.0f;

void cos_Callback(const std_msgs::Float32::ConstPtr& rcv_msg){

  buf = rcv_msg->data;
}

void chatterCallback(const std_msgs::Int32::ConstPtr& rcv_msg){

  float_msg.data = ((float)rcv_msg->data) + buf;

  ROS_INFO("I heard: [%d], and add [%.1f]", rcv_msg->data, buf);
  chatter_pub.publish(float_msg);
}

int main(int argc, char **argv){

  ros::init(argc, argv, "middle_event");

  ros::NodeHandle n;
  chatter_pub = n.advertise<std_msgs::Float32>("chatter_float", 1000);

  ros::Subscriber sub = n.subscribe("chatter_int", 1000, chatterCallback);
  ros::Subscriber sub_cos = n.subscribe("chatter_cos", 1000, cos_Callback);

  ros::spin();

  return 0;
}