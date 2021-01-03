#include "ros/ros.h"
#include <std_msgs/Float32MultiArray.h>
#include <math.h>
#include "beginner_tutorial/carPosition.h"


ros::Publisher target_x_y_array_pub;
std_msgs::Float32MultiArray target_x_y_array;

float buf_x_y_theta_array[3];
int count = 0;

void x_y_theta_array_callback(const beginner_tutorial::carPosition::ConstPtr& x_y_theta_array){

  buf_x_y_theta_array[0] = x_y_theta_array->x;
  buf_x_y_theta_array[1] = x_y_theta_array->y;
  buf_x_y_theta_array[2] = x_y_theta_array->yaw;
}

void timer_callback(const ros::TimerEvent& e){
    //目標コースy=1+sin(6.28 * x / 166.6)
    //点列間隔は0.2mで、100m先まで返す。つまり点列は500個

    int i;
    int iter;
    float x;
    float space = 0.2;
    iter = 500;
    for (i=0; i<iter; i++) {
    x = buf_x_y_theta_array[0] + space*i;
    target_x_y_array.data[2*i] = x;
    //target_x_y_array.data[2*i+1] = 1+sin(6.28 * x / 166.6);
    target_x_y_array.data[2*i+1] = 1;
    //ROS_INFO("x: %.1f  y: %.1f", target_x_y_array.data[2*i], target_x_y_array.data[2*i+1]);
    }
    
    target_x_y_array_pub.publish(target_x_y_array);
    ROS_INFO("<<<<<<<<<<<<<< published >>>>>>>>>>>>>>>");
}

/*
int count = 0;
void timer_callback(const ros::TimerEvent& e){
    //目標コースとしてx軸を想定
    ++count;
    target_x_y_array.data[0] = 8.33f*0.025*(float)count;
    target_x_y_array.data[1] = 1.0;
    
    ROS_INFO("x: %.1f  y: %.1f", target_x_y_array.data[0], target_x_y_array.data[1]);
    target_x_y_array_pub.publish(target_x_y_array);
}
*/

int main(int argc, char **argv){

  ros::init(argc, argv, "target_x_y_array");

  ros::NodeHandle n;
  for(int i = 0;i < 3;++i){
	  buf_x_y_theta_array[i];
  }
  target_x_y_array.data.resize(1005);
  target_x_y_array_pub = n.advertise<std_msgs::Float32MultiArray>("target_x_y_array", 10000);

  ros::Subscriber x_y_theta_array_sub = n.subscribe("car_position", 1000, x_y_theta_array_callback);
  ros::Timer timer = n.createTimer(ros::Duration(0.1), timer_callback);
  ros::spin();

  return 0;
}
