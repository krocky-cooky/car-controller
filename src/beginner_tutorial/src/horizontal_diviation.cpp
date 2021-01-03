#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include <std_msgs/Float32MultiArray.h>
#include "beginner_tutorial/carPosition.h"
#include <math.h>

ros::Publisher horizontal_diviation_pub;
std_msgs::Float32 horizontal_diviation;

float buf_view_point_x_y_theta_array[3];
float buf_target_x_y_array[1000];


/*
void view_point_x_y_theta_array_callback(const beginner_tutorial::carPosition::ConstPtr& veiw_point_x_y_theta_array){

  buf_view_point_x_y_theta_array[0] = veiw_point_x_y_theta_array->x;
  buf_view_point_x_y_theta_array[1] = veiw_point_x_y_theta_array->y;
  buf_view_point_x_y_theta_array[2] = veiw_point_x_y_theta_array->yaw;
}

void target_x_y_array_callback(const std_msgs::Float32MultiArray::ConstPtr& target_x_y_array){
  float delta_x;
  float delta_y;
  float temp_horizontal_diviation;

  //目標点列データのなかで前方注視点との距離が最小のものを探す
  horizontal_diviation.data = 1000;
  int i;
  int iter;
  iter = 500;
  for (i=0; i<iter; i++) {
  delta_x = buf_view_point_x_y_theta_array[0] - target_x_y_array->data.at(2*i);
  delta_y = buf_view_point_x_y_theta_array[1] - target_x_y_array->data.at(2*i+1);
  temp_horizontal_diviation = sqrtf(powf(delta_x, 2.0f) + powf(delta_y, 2.0f));
  if (temp_horizontal_diviation < horizontal_diviation.data){
    horizontal_diviation.data = temp_horizontal_diviation;
  } 
  }

  ROS_INFO("horizontal_diviation: [%.1f]", horizontal_diviation.data);
  horizontal_diviation_pub.publish(horizontal_diviation);
}
*/
void target_x_y_array_callback(const std_msgs::Float32MultiArray::ConstPtr& target_x_y_array){
  int i;
  int iter;
  iter = 500;
  ROS_INFO("target callback");
  for (i=0; i<iter; i++) {
  buf_target_x_y_array[2*i] = target_x_y_array->data.at(2*i);
  buf_target_x_y_array[2*i+1] = target_x_y_array->data.at(2*i);
  }
}

void view_point_x_y_theta_array_callback(const beginner_tutorial::carPosition::ConstPtr& veiw_point_x_y_theta_array){
  float delta_x;
  float delta_y;
  float temp_horizontal_diviation;

  //目標点列データのなかで前方注視点との距離が最小のものを探す
  horizontal_diviation.data = 1000;
  int i;
  int iter;
  iter = 500;
  for (i=0; i<iter; i++) {
  delta_x = veiw_point_x_y_theta_array->x - buf_target_x_y_array[2*i];
  delta_y = veiw_point_x_y_theta_array->y - buf_target_x_y_array[2*i+1];
  temp_horizontal_diviation = sqrtf(powf(delta_x, 2.0f) + powf(delta_y, 2.0f));
  delta_y= 1e-8;
  if (temp_horizontal_diviation < abs(horizontal_diviation.data)){
	  temp_horizontal_diviation *= -abs(delta_y)/delta_y;
    horizontal_diviation.data = temp_horizontal_diviation;
  } 
  
  }

  ROS_INFO("horizontal_diviation: [%.1f]", horizontal_diviation.data);
  horizontal_diviation_pub.publish(horizontal_diviation);
}


int main(int argc, char **argv){

  ros::init(argc, argv, "horizontal_diviation");
  for(int i = 0; i < 3; ++i){
	  buf_view_point_x_y_theta_array[i] = 0;
  }
  for(int i = 0;i < 1000; ++i){
	  buf_target_x_y_array[i] = 0;
  }
  ROS_INFO("horizontal_diviation node started!");

  ros::NodeHandle n;
  horizontal_diviation_pub = n.advertise<std_msgs::Float32>("horizontal_diviation", 1000);
  ros::Subscriber view_point_x_y_theta_array_sub = n.subscribe("view_point_x_y_theta_array", 1000, view_point_x_y_theta_array_callback);
  ros::Subscriber target_x_y_array_sub = n.subscribe("target_x_y_array", 10000, target_x_y_array_callback);

  ros::spin();

  return 0;
}
