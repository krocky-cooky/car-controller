#include <cmath>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorial/steerAndVelocity.h"
#include "beginner_tutorial/carPosition.h"


double FREQUENCY = 1000;

struct Car{
	double x,y; // position of the car
	double yaw; // yaw of the car
	double dt;
	const double lr=1.6,lf=1.1,kr=60,kf=55,ksw=1,m=1500;
	Car(double _dt):x(0),y(0),yaw(0){
	dt = _dt/1000;
	}

	void move(double st,double vel){
		double l = lf + lr;
		double A = -m*(lf*kf-lr*kr)/(2*l*l*kf*kr);
		double delta = st/ksw;
		double gamma = vel*delta/(1+A*vel*vel)/l;
		double beta = (1-m*lf*vel*vel/(2*l*lr*kr))*lr*delta;
		beta /= (1+A*vel*vel)*l;

		double dx = vel*std::cos(yaw + beta)*dt;
		double dy = vel*std::sin(yaw + beta)*dt;
		double dyaw = st*dt;
		x += dx;
		y += dy;
		yaw += dyaw;
	}
};

Car mycar(FREQUENCY);
ros::Publisher pub;

void yawRateCallback(const beginner_tutorial::steerAndVelocity::ConstPtr& msg){
	double st = msg->steer
	float vel=8.33f
	mycar.move(st,vel);
	ROS_INFO("x : %lf,y : %lf,yaw : %lf",mycar.x,mycar.y,mycar.yaw);
	beginner_tutorial::carPosition message;
	message.x = mycar.x;
	message.y = mycar.y;
	message.yaw = mycar.yaw;
	pub.publish(message);

}

int main(int argc,char **argv){
	ros::init(argc,argv,"car_position");
	ROS_INFO("node starged!");
	ros::NodeHandle n;
	pub = n.advertise<beginner_tutorial::carPosition>("car_position",1000);
	ros::Subscriber sub = n.subscribe("positionTalker",1000,yawRateCallback);
	 
	ros::spin();
	return 0;
}

