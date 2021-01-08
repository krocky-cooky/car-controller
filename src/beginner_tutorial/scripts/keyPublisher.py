#!/usr/bin/env python
# -*-coding: utf-8 -*-

import rospy
import sys,select,termios,tty
from beginner_tutorial.msg import steerAndVelocity
import numpy as np



pub = rospy.Publisher('positionTalker',steerAndVelocity,queue_size=10)

def getKey():
    if select.select([sys.stdin],[],[],0) == ([sys.stdin],[],[]):
        key = sys.stdin.read(1)
        return key
    #print(select.select([sys.stdin],[],[],0))
    return None


if __name__ == '__main__':
    rospy.init_node('publish_keyboard')
    settings = termios.tcgetattr(sys.stdin)
    tty.setcbreak(sys.stdin.fileno())

    msg = steerAndVelocity()
    steer = 0.0
    velocity = 10.0
    r = rospy.Rate(1)
    while not rospy.is_shutdown():
        try:
            key = getKey()
        finally:
            termios.tcsetattr(sys.stdin,termios.TCSADRAIN,settings)
        if key == 'a':
            if steer == np.deg2rad(20):
                steer = 0.0
            else:
                steer = np.deg2rad(20)
        if key == 'd':
            if steer == np.deg2rad(-20):
                steer = 0.0
            else:
                steer = np.deg2rad(-20)
        if key == 's':
            if velocity == 0.0:
                velocity = 10.0
            else:
                velocity = 0.0
        #rospy.loginfo('key : {}'.format(key))
        msg.steer = steer
        msg.velocity = velocity
        pub.publish(msg)
        r.sleep()
