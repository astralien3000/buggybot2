import config
import numpy as np

def shoulder_matrix(bot, q0, q1, q2):
    return np.transpose([
        [1,0,0,0],
        [0,np.cos(q0),-np.sin(q0),0],
        [0,np.sin(q0),np.cos(q0),0],
        [0,0,0,1]])

def arm_matrix(bot, q0, q1, q2):
    return np.transpose([
        [0,-np.cos(q1),np.sin(q1),bot.L3],
        [1,0,0,bot.L4],
        [0,np.sin(q1),np.cos(q1),-bot.L5],
        [0,0,0,1]])

def forearm_matrix(bot, q0, q1, q2):
    return np.transpose([
        [1,0,0,bot.L6],
        [0,np.cos(q2),-np.sin(q2),0],
        [0,np.sin(q2),np.cos(q2),-bot.L7],
        [0,0,0,1]])
