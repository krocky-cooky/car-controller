#!/usr/bin/env python
#import visdom
import rospy
import numpy as np
from beginner_tutorial.msg import carPosition
import matplotlib.pyplot as plt
import time

position_list = list()
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
    #print(time.time())

def listener():
    rospy.init_node('plot')
    rospy.loginfo('This is drawing node')
    rospy.Subscriber('/car_position',carPosition,call_back)
    rospy.spin()


if __name__ == '__main__':
    listener()



