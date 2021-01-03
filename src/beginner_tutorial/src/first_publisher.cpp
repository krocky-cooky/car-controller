#include "beginner_tutorial/steerAndVelocity.h"
#include "ros/ros.h"


ros::Publisher pub;

int main(int argc,char **argv){
	ros::init(argc,argv,"first_publisher");
	ros::NodeHandle n;
	ROS_INFO("first publisher node!");
	pub = n.advertise<beginner_tutorial::steerAndVelocity>("positionTalker",1000);
	beginner_tutorial::steerAndVelocity message;
	message.steer = 10;
	message.velocity = 8.33f;
	sleep(3);
	pub.publish(message);
	return 0;
}
