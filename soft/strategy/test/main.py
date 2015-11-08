import bpy
import config
import mesh_generator as mg
import mgd
import mgi
import robot

import numpy as np


bot = config.Robot
scn = bpy.data.scenes[0]

left_front = np.transpose([[1,0,0,bot.L0],[0,1,0,bot.L1],[0,0,1,bot.L2],[0,0,0,1]])
right_front = np.transpose([[1,0,0,bot.L0],[0,-1,0,-bot.L1],[0,0,1,bot.L2],[0,0,0,1]])
left_back = np.transpose([[-1,0,0,-bot.L0],[0,1,0,bot.L1],[0,0,1,bot.L2],[0,0,0,1]])
right_back = np.transpose([[-1,0,0,-bot.L0],[0,-1,0,-bot.L1],[0,0,1,bot.L2],[0,0,0,1]])


def test(dummy):
    tar = bpy.data.objects['target']
    #if not bpy.data.scenes[0].is_updated:
    #    return
    leg = robot.RobotLeg('testleg')
    loc = tar.location
    s = mgi.get_q_filtered(config.Robot, [0,0,0], loc[0],loc[1],loc[2])
    if len(s) > 0:
        leg.command([s[0][0], s[0][1], s[0][2]])

test(0)

class ToolsPanel(bpy.types.Panel):
    bl_label = "Hello from Tools"
    bl_space_type = "VIEW_3D"
    bl_region_type = "TOOLS"
 
    def draw(self, context):
        self.layout.operator("hello.hello")

bpy.utils.register_module(__name__)

#bpy.app.handlers.scene_update_post.append(test)

# for y in range(-10,10):
#     s = mgi.get_q_filtered(bot, [0,0,0], 0,y/100.0,0.08)
#     for q in s:
#         sh = mg.create_shoulder(bot, scn, 'test0')
#         ar = mg.create_arm(bot, scn, 'test1')
#         fa = mg.create_forearm(bot, scn, 'test2')
#         ar.parent = sh
#         fa.parent = ar
#         q0 = q[0]
#         q1 = q[1]
#         q2 = q[2]
#         msh = mgd.shoulder_matrix(bot, -q0,q1,q2)
#         mar = mgd.arm_matrix(bot, -q0,q1,q2)
#         mfa = mgd.forearm_matrix(bot, -q0,q1,q2)
#         sh.matrix_local = msh
#         ar.matrix_local = mar
#         fa.matrix_local = mfa
