#!/usr/bin/env python
#import visdom
import rospy
import numpy as np
from beginner_tutorial.msg import carPosition
import matplotlib.pyplot as plt
import time

x_list = list()
y_list = list()
cnt = 0

def call_back(data):
    x = data.x
    y = data.y
    yaw = data.yaw
    plt.scatter(
            x = x,
            y = y
            )
    plt.draw()
    plt.pause(0.01)
    """
    print(len(x_list))
    if len(x_list) % 1000== 0:
        x_sub = x_list[0:len(x_list):10]
        y_sub = y_list[0:len(y_list):10]
        plt.plot(x_sub,y_sub)
        plt.plot(x_sub,x_sub)
        plt.show()
        """

def listener():
    rospy.init_node('plot')
    rospy.loginfo('This is drawing node')
    rospy.Subscriber('/car_position',carPosition,call_back)
    rospy.spin()


if __name__ == '__main__':
    listener()


