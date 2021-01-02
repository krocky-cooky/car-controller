#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include <std_msgs/Float32MultiArray.h>
#include "beginner_tutorial/steerAndVelocity.h"
#include <math.h>

ros::Publisher steering_pub;
beginner_tutorial::steerAndVelocity sv;
const float gain = 2.0;
const float vel = 8.33f;

void horizontal_diviation_callback(const std_msgs::Float32::ConstPtr& horizontal_diviation){

  sv.steer = horizontal_diviation->data * gain;
  sv.velocity = vel;


  ROS_INFO("steering: [%.1f]", sv.steer);
  steering_pub.publish(sv);

}

int main(int argc, char **argv){

  ros::init(argc, argv, "steering");

  ros::NodeHandle n;
  steering_pub = n.advertise<beginner_tutorial::steerAndVelocity>("positionTalker", 1000);
  ros::Subscriber horizontal_diviation_sub = n.subscribe<std_msgs::Float32>("horizontal_diviation", 1000, horizontal_diviation_callback);
  ros::spin();

  return 0;
}
