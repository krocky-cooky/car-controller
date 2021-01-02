#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include <std_msgs/Float32MultiArray.h>
#include "beginner_tutorial/carPosition.h"
#include <math.h>

ros::Publisher horizontal_diviation_pub;
std_msgs::Float32 horizontal_diviation;

float buf_view_point_x_y_theta_array[3];


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

int main(int argc, char **argv){

  ros::init(argc, argv, "horizontal_diviation");

  ros::NodeHandle n;
  horizontal_diviation_pub = n.advertise<std_msgs::Float32>("horizontal_diviation", 1000);
  ros::Subscriber view_point_x_y_theta_array_sub = n.subscribe("view_point_x_y_theta_array", 1000, view_point_x_y_theta_array_callback);
  ros::Subscriber target_x_y_array_sub = n.subscribe("target_x_y_array", 100000, target_x_y_array_callback);

  ros::spin();

  return 0;
}
