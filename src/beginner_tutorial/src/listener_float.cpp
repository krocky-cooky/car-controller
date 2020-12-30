#include "ros/ros.h"
#include "std_msgs/Float32.h"

void chatterCallback(const std_msgs::Float32::ConstPtr& msg){
  ROS_INFO("I heard: [%.1f]", msg->data);
}

int main(int argc, char **argv){

  ros::init(argc, argv, "listener_float");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter_float", 1000, chatterCallback);

  ros::spin();

  return 0;
}