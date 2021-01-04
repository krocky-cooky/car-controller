#include <cmath>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorial/steerAndVelocity.h"
#include "beginner_tutorial/carPosition.h"


double FREQUENCY = 20;

struct Car{
	double x,y; // position of the car
	double yaw; // yaw of the car
	double dt;
	double lr,lf,kr,kf,ksw,m;
	Car(double _dt):x(0),y(0),yaw(0){
		lr=1.6;lf=1.1;kr=60;kf=55;ksw=10;m=1500;
		dt = _dt/1000;
	}

	void move(double st,double vel){
		double l = lf + lr;
		double A = -m*(lf*kf-lr*kr)/(2*l*l*kf*kr);
		double delta = st/ksw;
		double gamma = vel*delta/(1+A*vel*vel)/l;
		double beta = (1-m*lf*vel*vel/(2*l*lr*kr))*lr*delta;
		beta /= (1+A*vel*vel)*l;
		ROS_INFO("beta : %lf",beta);
		beta = 0;
		double dx = vel*std::cos(yaw + beta)*dt;
		double dy = vel*std::sin(yaw + beta)*dt;
		double dyaw = gamma*dt;
		x += dx;
		y += dy;
		yaw += dyaw;
	}
};

Car mycar(FREQUENCY);
ros::Publisher pub;
beginner_tutorial::carPosition message;

void yawRateCallback(const beginner_tutorial::steerAndVelocity::ConstPtr& msg){
	double st = msg->steer;
	double vel= msg->velocity;
	ROS_INFO("get steer : %lf, vel : %lf",st,vel);
	mycar.move(st,vel);
	ROS_INFO("x : %lf,y : %lf,yaw : %lf",mycar.x,mycar.y,mycar.yaw);
	message.x = mycar.x;
	message.y = mycar.y;
	message.yaw = mycar.yaw;

}

void timerCallback(const ros::TimerEvent& e){
	pub.publish(message);
}

void initialize(void){
	message.x = 0;
	message.y = 0;
	message.yaw = 0;
}

int main(int argc,char **argv){
	ros::init(argc,argv,"car_position");
	ROS_INFO("kuroki node starged!");
	initialize();
	ros::NodeHandle n;
	pub = n.advertise<beginner_tutorial::carPosition>("car_position",1000);
	ros::Subscriber sub = n.subscribe("positionTalker",1000,yawRateCallback);
	ros::Timer timer = n.createTimer(ros::Duration(0.02),timerCallback);
	 
	ros::spin();
	return 0;
}

