import bpy
from mesh_generator import *
import config
import mgd

scn = bpy.data.scenes[0]

class RobotLeg:
    def __init__(self, name):
        if(bpy.data.objects.find(name + '_shoulder_obj') != -1):
            self.shoulder = bpy.data.objects[name + '_shoulder_obj']
            self.arm = bpy.data.objects[name + '_arm_obj']
            self.forearm = bpy.data.objects[name + '_forearm_obj']
        else:
            self.shoulder = create_shoulder(config.Robot, scn, name + '_shoulder')
            self.arm = create_arm(config.Robot, scn, name + '_arm')
            self.forearm = create_forearm(config.Robot, scn, name + '_forearm')
            self.command([0,0,0])
    def command(self, q):
        self.arm.parent = self.shoulder
        self.forearm.parent = self.arm
        self.shoulder.matrix_local = mgd.shoulder_matrix(config.Robot, q[0], q[1], q[2])
        self.arm.matrix_local = mgd.arm_matrix(config.Robot, q[0], q[1], q[2])
        self.forearm.matrix_local = mgd.forearm_matrix(config.Robot, q[0], q[1], q[2])
        print(self.forearm.matrix_local)
