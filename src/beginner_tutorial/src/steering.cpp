#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include <std_msgs/Float32MultiArray.h>
#include <math.h>

ros::Publisher steering_pub;
std_msgs::Float32 steering;
const float gain = 2.0;

void horizontal_diviation_callback(const std_msgs::Float32::ConstPtr& horizontal_diviation){

  steering.data = horizontal_diviation->data * gain;


  ROS_INFO("steering: [%.1f]", steering.data);
  steering_pub.publish(steering);

}

int main(int argc, char **argv){

  ros::init(argc, argv, "steering");

  ros::NodeHandle n;
  steering_pub = n.advertise<std_msgs::Float32>("steering", 1000);
  ros::Subscriber horizontal_diviation_sub = n.subscribe<std_msgs::Float32>("horizontal_diviation", 1000, horizontal_diviation_callback);
  ros::spin();

  return 0;
}