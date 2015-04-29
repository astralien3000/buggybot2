import numpy as np
import paul as p
import config

def get_q(bot, x, y, z):
    s0 = p.paul2(z, y, bot.L6+bot.L4+bot.L10)
    s = []
    for q0 in s0:
        c0 = np.cos(q0)
        s0 = np.sin(q0)
        z0 = c0 * z
        y0 = s0 * y
        s1 = p.paul6(
            bot.L9,
            bot.L7,
            bot.L3 - x,
            -bot.L5 - z0 + y0,
            bot.L8)
        for q in s1:
            q1 = q[0]
            q3 = -q[1]
            q2 = q3 - q1
            s.append([q0, q1, q2])
    return s

def dist(q0, q1):
    ret = 0
    for i in range(0, len(q0)):
        ret = ret + np.abs(q0[i] - q1[i])
    return ret

_deg = np.pi / 180.0

def q0_predicate(a):
    return -30*_deg < a and a < 150*_deg

def q1_predicate(a):
    return -90*_deg < a and a < 90*_deg

def q2_predicate(a):
    return 0*_deg < a and a < 180*_deg

def q_predicate(q):
    ret = q0_predicate(q[0])
    ret = ret and q1_predicate(q[1])
    ret = ret and q2_predicate(q[2])
    return ret

def modulo(a):
    a_deg = a/_deg
    a_ent = int(a_deg)
    a_dec = a_deg - float(a_ent)
    return (((a_ent + 180) % 360) - 180 + a_dec) * _deg

def get_q_modulo(bot, x, y, z):
    s = get_q(bot, x, y, z)
    ret = []
    for q in s:
        ret.append([modulo(q[0]), modulo(q[1]), modulo(q[2])])
    return ret

def get_q_filtered(bot, x, y, z):
    s = get_q_modulo(bot, x, y, z)
    ret = []
    for q in s:
        if q_predicate(q):
            ret.append(q)
    return ret
