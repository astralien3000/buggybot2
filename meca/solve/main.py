import bpy
import config
import mesh_generator as mg
import mgd
import mgi

import numpy as np

bot = config.Robot
scn = bpy.data.scenes[0]
s = mgi.get_q_filtered(bot, [0,0,0], 0,0,0.08)


for q in s:
    sh = mg.create_shoulder(bot, scn, 'test0')
    ar = mg.create_arm(bot, scn, 'test1')
    fa = mg.create_forearm(bot, scn, 'test2')

    ar.parent = sh
    fa.parent = ar

    q0 = q[0]
    q1 = q[1]
    q2 = q[2]

    msh = mgd.shoulder_matrix(bot, -q0,q1,q2)
    mar = mgd.arm_matrix(bot, -q0,q1,q2)
    mfa = mgd.forearm_matrix(bot, -q0,q1,q2)

    sh.matrix_local = msh
    ar.matrix_local = mar
    fa.matrix_local = mfa
