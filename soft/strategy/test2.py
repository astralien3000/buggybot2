import bpy
import numpy as np
import mgd
import mgi

import servo

import socket
import protocol

import time

def trans(x, y, z):
    return [
        [1,0,0,x],
        [0,1,0,y],
        [0,0,1,z],
        [0,0,0,1]]

def scal(x, y, z):
    return [
        [x,0,0,0],
        [0,y,0,0],
        [0,0,z,0],
        [0,0,0,1]]

def rot_z(a):
    return [
        [np.cos(a),-np.sin(a),0,0],
        [np.sin(a),np.cos(a),0,0],
        [0,0,1,0],
        [0,0,0,1]]

def rot_x(a):
    return [
        [1,0,0,0],
        [0,np.cos(a),-np.sin(a),0],
        [0,np.sin(a),np.cos(a),0],
        [0,0,0,1]]

def rot_y(a):
    return [
        [np.cos(a),0,-np.sin(a),0],
        [0,1,0,0],
        [np.sin(a),0,np.cos(a),0],
        [0,0,0,1]]

def inv_SO3(m):
    tR = np.transpose(m[0:3][0:3])
    T = m[3:4][0:3]
    ret = np.transpose(np.zeros((4,4)))
    for i in range(0,3):
        for j in range(0,3):
            ret[i][j] = tR[i][j]
        ret[i][3] = -T[0][i]
    ret[3][3] = 1.0
    return ret

def inv_scal(m):
    ret = np.transpose(np.zeros((4,4)))
    for i in range(0,4):
            ret[i][i] = 1.0/m[i][i]
    ret[3][3] = 1.0
    return ret

def getobj(name):
    return bpy.data.objects[name]

def get_full_mat(mgd_mat, name):
    if mgd_mat[name]['parent'] == None:
        return mgd_mat[name]['mat']
    else:
        return np.dot(get_full_mat(mgd_mat, mgd_mat[name]['parent']), mgd_mat[name]['mat'])

_deg = np.pi / 180.0

# CONFIG
_cm = 10.0
class LegConfig:
    L0 = 9.8 * _cm
    L1 = 5.0 * _cm
    L2 = 1.5 * _cm
    L3 = 0.0 * _cm
    L4 = 0.0 * _cm
    L5 = 3.3 * _cm
    L6 = 0.0 * _cm
    L7 = 7.0 * _cm
    L8 = 5.5 * _cm
    L9 = 2.1 * _cm
    L10 = 0.5 * _cm


def mat_node(mat, parent):
    return { 'mat' : mat, 'parent' : parent }

class MGD:
    def __init__(self):
        q = [0,0,0]
        legs = ['LF', 'RF', 'RB', 'LB']
        self.mat = dict()
        # MINI
        self.mat['Mini'] = mat_node(
            scal(0.1,0.1,0.1), 
            None)
        # ROBOT
        self.mat['Robot'] = mat_node(
            rot_z(90*_deg), 
            'Mini')
        # BASE
        self.mat['Base'] = mat_node(
            np.dot(rot_z(-90*_deg), rot_x(90 * _deg)), 
            'Robot')
        # SIDE_REF
        self.mat['LF.SideRef'] = mat_node(
            scal(1,1,1), 
            'Robot')
        self.mat['RF.SideRef'] = mat_node(
            scal(1,-1,1), 
            'Robot')
        self.mat['RB.SideRef'] = mat_node(
            scal(-1,-1,1), 
            'Robot')
        self.mat['LB.SideRef'] = mat_node(
            scal(-1,1,1), 
            'Robot')
        for l in legs:
            # LEG_REF
            self.mat[l+'.LegRef'] = mat_node(
                mgd.leg_matrix(LegConfig, *q), 
                l+'.SideRef')
            # INV_LEG_REF
            self.mat['inv.'+l+'.LegRef'] = mat_node(
                np.linalg.inv(self.get_full_mat(l+'.LegRef')),
                None)
            # SHOULDER_BASE
            self.mat[l+'.ShoulderBase'] = mat_node(
                np.dot(trans(-2,-19.5,13.5), np.dot(rot_z(180*_deg), rot_x(-90*_deg))), 
                l+'.LegRef')
            # SERVO_BASE
            self.mat[l+'.ServoBase'] = mat_node(
                np.dot(np.dot(trans(-59.25,0,-1), rot_x(-90 * _deg)), rot_z(-90*_deg)), 
                l+'.LegRef')
            # SHOULDER_REF
            self.mat[l+'.ShoulderRef'] = mat_node(
                mgd.shoulder_matrix(LegConfig, *q), 
                l+'.LegRef')
            # SHOULDER
            self.mat[l+'.Shoulder'] = mat_node(
                np.dot(np.dot(trans(0,10,-37.5), rot_x(0 * _deg)), rot_z(180*_deg)), 
                l+'.ShoulderRef')
            # SERVO_ARM
            self.mat[l+'.ServoArm'] = mat_node(
                np.dot(np.dot(trans(0,-16,-33.8), rot_x(0 * _deg)), rot_y(180*_deg)), 
                l+'.ShoulderRef')
            # ARM_REF
            self.mat[l+'.ArmRef'] = mat_node(
                mgd.arm_matrix(LegConfig, *q), 
                l+'.ShoulderRef')
            # ARM
            self.mat[l+'.Arm'] = mat_node(
                np.dot(np.dot(trans(0,9.5,-35), rot_z(180 * _deg)), rot_y(180*_deg)), 
                l+'.ArmRef')
            # FOREARM_REF
            self.mat[l+'.ForearmRef'] = mat_node(
                mgd.forearm_matrix(LegConfig, *q), 
                l+'.ArmRef')
            # SERVO_FOREARM
            self.mat[l+'.ServoForearm'] = mat_node(
                np.dot(np.dot(trans(-16,0,0), rot_z(-90 * _deg)), rot_y(0*_deg)), 
                l+'.ForearmRef')
            # FOREARM
            self.mat[l+'.Forearm'] = mat_node(
                np.dot(np.dot(trans(4.5,15,-23), rot_z(180 * _deg)), rot_y(0*_deg)), 
                l+'.ForearmRef')
            # ENDPOINT
            self.mat[l+'.Endpoint'] = mat_node(
                trans(LegConfig.L10,0,-LegConfig.L8), 
                l+'.ForearmRef')
    def get_full_mat(self, name):
        if self.mat[name]['parent'] == None:
            return self.mat[name]['mat']
        else:
            return np.dot(self.get_full_mat(self.mat[name]['parent']), self.mat[name]['mat'])
    def update_leg(self, l, q):
        # SHOULDER_REF
        self.mat[l+'.ShoulderRef'] = mat_node(
            mgd.shoulder_matrix(LegConfig, *q), 
            l+'.LegRef')
        # SHOULDER
        self.mat[l+'.Shoulder'] = mat_node(
            np.dot(np.dot(trans(0,10,-37.5), rot_x(0 * _deg)), rot_z(180*_deg)), 
            l+'.ShoulderRef')
        # SERVO_ARM
        self.mat[l+'.ServoArm'] = mat_node(
            np.dot(np.dot(trans(0,-16,-33.8), rot_x(0 * _deg)), rot_y(180*_deg)), 
            l+'.ShoulderRef')
        # ARM_REF
        self.mat[l+'.ArmRef'] = mat_node(
            mgd.arm_matrix(LegConfig, *q), 
            l+'.ShoulderRef')
        # ARM
        self.mat[l+'.Arm'] = mat_node(
            np.dot(np.dot(trans(0,9.5,-35), rot_z(180 * _deg)), rot_y(180*_deg)), 
            l+'.ArmRef')
        # FOREARM_REF
        self.mat[l+'.ForearmRef'] = mat_node(
            mgd.forearm_matrix(LegConfig, *q), 
            l+'.ArmRef')
    def get_angles_mgi(self, leg, pos):
        vec = np.transpose([pos[0], pos[1], pos[2], 1])
        t = self.get_full_mat('inv.'+leg+'.LegRef')
        vec = np.dot(t, vec)
        sols = mgi.get_q_filtered(LegConfig, vec[0], vec[1], vec[2])
        if len(sols):
            return sols[0]
        return None
    

    
        
def show_mgd(mymgd, leg, q):
    # BASE
    base = getobj('Base')
    base.matrix_local = np.transpose(mymgd.get_full_mat('Base'))
    # SHOULDER_BASE
    shoulder_base = getobj('Leg.'+leg+'.ShoulderBase')
    shoulder_base.parent = None
    shoulder_base.matrix_local = np.transpose(mymgd.get_full_mat(leg+'.ShoulderBase'))
    # SERVO_BASE
    servo_base = getobj('Leg.'+leg+'.ServoBase')
    servo_base.parent = None
    servo_base.matrix_local = np.transpose(mymgd.get_full_mat(leg+'.ServoBase'))
    # SHOULDER
    servo_base = getobj('Leg.'+leg+'.Shoulder')
    servo_base.parent = None
    servo_base.matrix_local = np.transpose(mymgd.get_full_mat(leg+'.Shoulder'))
    # SERVO_ARM
    servo_base = getobj('Leg.'+leg+'.ServoArm')
    servo_base.parent = None
    servo_base.matrix_local = np.transpose(mymgd.get_full_mat(leg+'.ServoArm'))
    # ARM
    servo_base = getobj('Leg.'+leg+'.Arm')
    servo_base.parent = None
    servo_base.matrix_local = np.transpose(mymgd.get_full_mat(leg+'.Arm'))
    # SERVO_FOREARM
    servo_base = getobj('Leg.'+leg+'.ServoForearm')
    servo_base.parent = None
    servo_base.matrix_local = np.transpose(mymgd.get_full_mat(leg+'.ServoForearm'))
    # FOREARM
    servo_base = getobj('Leg.'+leg+'.Forearm')
    servo_base.parent = None
    servo_base.matrix_local = np.transpose(mymgd.get_full_mat(leg+'.Forearm'))
    # ENDPOINT
    servo_base = getobj('Leg.'+leg+'.Endpoint')
    servo_base.parent = None
    servo_base.matrix_local = np.transpose(mymgd.get_full_mat(leg+'.Endpoint'))

###############
# TEST MGI
def send_cmd(seri, sid, val):
    msg = protocol.ServoAngle()
    #print(val)
    msg['id'] = servo.SERVO[sid]
    msg['angle'] = int(val)
    seri.send(msg.pack())
    time.sleep(0.0001)

def send_ctrl(seri, vals):
    msg = protocol.ServosCtrl()
    #print(val)
    for k in vals.keys():
        msg[k.lower()] = int(vals[k])
        print(k,msg[k.lower()])
    seri.send(msg.pack())
    time.sleep(0.0001)

default_pos = {
    'LF' : [-9, 9,-12],
    'RF' : [ 9, 9,-12],
    'RB' : [ 9,-9,-12],
    'LB' : [-9,-9,-12],
}

config_walk = {
    'LF' : { 't_begin' : 0 },
    'RF' : { 't_begin' : 20 },
    'RB' : { 't_begin' : 10 },
    'LB' : { 't_begin' : 30 },
    't_length' : 5,
    't_period' : 40,
    'height' : 6,
    'delta_y' : 6,
    'delta_y2' : 0.5,
    'delta_x' : 0.5,
    't_delta' : 2,
    'angle_side' : 3,
}

def walk(leg, t):
    t = float(t) / 2
    d = default_pos[leg]
    z = d[2]
    beg = config_walk[leg]['t_begin']
    if beg <= t and t <= beg + config_walk['t_length']:
        z += config_walk['height']
    off_t = t - config_walk[leg]['t_begin']
    if off_t < 0:
        off_t += config_walk['t_period']
    y = d[1]
    if off_t <= config_walk['t_length']:
        y +=  (float(off_t) / config_walk['t_length'] - 1.0 / 2.0) * config_walk['delta_y']
    else:
        tt = off_t - config_walk['t_length']
        length = config_walk['t_period'] - config_walk['t_length']
        y -=  (float(tt) / length - 1.0 / 2.0) * config_walk['delta_y']
    x = d[0]
    if config_walk['LF']['t_begin']-config_walk['t_delta'] <= t and t <= config_walk['LF']['t_begin'] + config_walk['t_length'] + config_walk['t_delta']:
        x -= config_walk['delta_x']
        y += config_walk['delta_y2']
    if config_walk['LB']['t_begin']-config_walk['t_delta'] <= t and t <= config_walk['LB']['t_begin'] + config_walk['t_length'] + config_walk['t_delta']:
        x -= config_walk['delta_x']
        y -= config_walk['delta_y2']
    if config_walk['RF']['t_begin']-config_walk['t_delta'] <= t and t <= config_walk['RF']['t_begin'] + config_walk['t_length'] + config_walk['t_delta']:
        x += config_walk['delta_x']
        y += config_walk['delta_y2']
    if config_walk['RB']['t_begin']-config_walk['t_delta'] <= t and t <= config_walk['RB']['t_begin'] + config_walk['t_length'] + config_walk['t_delta']:
        x += config_walk['delta_x']
        y -= config_walk['delta_y2']
    return [x, y, z]

def test(sock, mymgd, leg):
    cur = bpy.data.scenes[0].frame_current
    target = getobj('Leg.'+leg+'.Target')
    loc = target.location
    pos = [loc[0], loc[1], loc[2]]
    #pos = walk(leg, cur)
    target.location[0] = pos[0]
    target.location[1] = pos[1]
    target.location[2] = pos[2]
    sol = mymgd.get_angles_mgi(leg, pos)
    if sol:
        mymgd.update_leg(leg, sol)
        show_mgd(mymgd, leg, sol)
        ret = {
            leg+'0' : sol[0]/_deg,
            leg+'1' : sol[1]/_deg,
            leg+'2' : sol[2]/_deg,
        }
        return ret
        #send_cmd(sock, leg +'0', sols[0][0]/_deg)
        #send_cmd(sock, leg +'1', sols[0][1]/_deg)
        #send_cmd(sock, leg +'2', sols[0][2]/_deg)
    return {}
        
        
def main(dummy = None):
    sock = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)
    sock.connect(('/tmp/buggybot2'))
    mymgd = MGD()
    mgd_mat = mymgd.mat
    vals = {}
    vals = dict(vals, **test(sock, mymgd, 'LF'))
    vals = dict(vals, **test(sock, mymgd, 'RF'))
    vals = dict(vals, **test(sock, mymgd, 'RB'))
    vals = dict(vals, **test(sock, mymgd, 'LB'))
    send_ctrl(sock, vals)
    sock.close()
    
bpy.app.handlers.scene_update_post.clear()
bpy.app.handlers.scene_update_post.append(main)
#main()