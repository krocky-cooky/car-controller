#include "ros/ros.h"
#include "beginner_tutorial/steerAndVelocity.h"
#include <cmath>



double deg2rad(double deg){
	double rad = deg/180*std::acos(-1);
	return rad;
}

double velocity = 0,steer = 0;

void callback(const beginner_tutorial::steerAndVelocity::ConstPtr& msg){
	velocity = msg->velocity;
	steer = msg->steer;
}

ros::Publisher pub;
beginner_tutorial::steerAndVelocity msg;


int main(int argc,char **argv){
	msg.steer = deg2rad(steer);
	msg.velocity = velocity;
	ros::init(argc,argv,"posTalker");

	ros::NodeHandle n;
	pub = n.advertise<beginner_tutorial::steerAndVelocity>("positionTalker",1000);
	ros::Subscriber sub = n.subscribe("keyboard",1000,callback);
	ros::Rate rate(10);

	while(ros::ok()){
		pub.publish(msg);
		ROS_INFO("published!");

		ros::spinOnce();
		rate.sleep();
	}
}
