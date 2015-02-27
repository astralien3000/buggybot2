import numpy as np
import mgi
import config
import matplotlib.pyplot as plt
import serial
import time

h_average = 0.15
h_max = 0.02
i_step_amp = 0.02
e_step_amp = 0.035
step_amp = i_step_amp + e_step_amp

def cycl(t):
    ret = t
    while(ret > np.pi):
        ret = ret - np.pi
    while(ret < 0):
        ret = ret + np.pi
    return ret

def x(t):
    if(0.0 <= t and t <= (np.pi/4.0)):
        return t * step_amp / (np.pi/4) - i_step_amp / 2
    else:
        return (np.pi/4 - t) * step_amp / (3*np.pi/4)+ i_step_amp / 2

def z(t):
    if(0.0 <= t and t <= (np.pi/4.0) - 0.1):
        return - h_average + h_max
    else:
        return - h_average

def y(t):
    return 0.045

def cmd(qn):
    ret = qn * 180.0 / np.pi
    return (int(ret) + 180) % 360 - 180

def cond_q0(q0):
    return q0 >= 0 and q0 <= 90

def cond_q1(q1):
    return q1 >= -90 and q1 <= 90

def cond_q2(q2):
    return q2 >= 0 and q2 <= 180

def cmd_q(q):
    ret = []
    for i in q:
        ret.append(cmd(i))
    return ret

def q(t):
    s = mgi.get_q(config.Robot, x(cycl(t)), y(cycl(t)), z(cycl(t)))
    ret = []
    for q in s:
        #print(cmd_q(q))
        if cond_q0(cmd(q[0])) and cond_q1(cmd(q[1])) and cond_q2(cmd(q[2])):
            ret.append(q)
    return ret

ser = serial.Serial('/dev/ttyACM0', 9600)

def send(q0, q1, q2):
    cmd0 = str(cmd(q0)) + '\n'
    ser.write(cmd0.encode())
    time.sleep(0.0001)
    cmd1 = str(cmd(q1)) + '\n'
    ser.write(cmd1.encode())
    time.sleep(0.0001)
    cmd2 = str(cmd(q2)) + '\n'
    ser.write(cmd2.encode())
    time.sleep(0.0001)
    print([cmd0, cmd1, cmd2])

def send_q(t):
    s = q(t)
    if len(s) > 0:
        ss = s[0]
        send(ss[0], ss[1], ss[2])
    else:
        send(0,0,0)
    s2 = q(np.pi - t)
    if len(s2) > 0:
        ss2 = s2[0]
        send(ss2[0], ss2[1], ss2[2])
    else:
        send(0,0,0)
    s3 = q(3 * np.pi/4 - t)
    if len(s3) > 0:
        ss3 = s3[0]
        send(ss3[0], ss3[1], ss3[2])
    else:
        send(0,0,0)
    s4 = q(t - np.pi / 4)
    if len(s4) > 0:
        ss4 = s4[0]
        send(ss4[0], ss4[1], ss4[2])
    else:
        send(0,0,0)
#    for i in range(0, 3):
#        ser.write(b'0\n')
#        time.sleep(0.01)

def anim():
    while 1:
        for t in np.arange(0.1, np.pi - 0.1, 0.03):
            send_q(t)

time.sleep(2)
ser.write(b'main\n')
anim()
