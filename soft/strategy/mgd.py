import config
import numpy as np

def leg_matrix(bot, q0, q1, q2):
    return np.transpose([
        [1,0,0,bot.L0],
        [0,1,0,bot.L1],
        [0,0,1,bot.L2],
        [0,0,0,1]])

def shoulder_matrix(bot, q0, q1, q2):
    return np.transpose([
        [1,0,0,0],
        [0,np.cos(q0),-np.sin(q0),0],
        [0,np.sin(q0),np.cos(q0),0],
        [0,0,0,1]])

def arm_matrix(bot, q0, q1, q2):
    a = -q1
    return np.transpose([
        [0,-np.cos(a),np.sin(a),bot.L3],
        [1,0,0,bot.L4],
        [0,np.sin(a),np.cos(a),-bot.L5],
        [0,0,0,1]])

def forearm_matrix(bot, q0, q1, q2):
    a = -q2
    return np.transpose([
        [1,0,0,bot.L6],
        [0,np.cos(a),-np.sin(a),-bot.L9],
        [0,np.sin(a),np.cos(a),-bot.L7],
        [0,0,0,1]])
