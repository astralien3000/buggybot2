import numpy as np
import paul as p
import config

def get_q(bot, x, y, z):
    s0 = p.paul2(z, y, bot.L6+bot.L4)
    s = []
    for q0 in s0:
        c0 = np.cos(q0)
        s0 = np.sin(q0)
        z0 = c0 * z
        y0 = s0 * y
        s1 = p.paul8(
            bot.L8,
            bot.L7,
            -bot.L5 + z0 - y0,
            x - bot.L3)
        for q1 in s1:
            q1[1] = q1[1] - q1[0]
            s.append([q0] + q1)
    return s

def dist(q0, q1):
    ret = 0
    for i in range(0, len(q0)):
        ret = ret + np.abs(q0[i] - q1[i])
    return ret

def get_q_filtered(bot, q_old, x, y, z):
    s = get_q(bot, x, y, z)
    min = [s[0], dist(q_old, s[0])]
    for q in s:
        d = dist(q_old, q)
        if d < min[1]:
            min = [q, d]
    return [min[0]]
