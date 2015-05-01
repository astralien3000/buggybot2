LEG = {
    'LF' : 0x01,
    'RF' : 0x02,
    'RB' : 0x04,
    'LB' : 0x08,
}

JOIN = {
    0 : 0x01,
    1 : 0x02,
    2 : 0x04,
}

SERVO = dict()

for l in LEG.items():
    for j in JOIN.items():
        SERVO[(l[0] + str(j[0]))] = (l[1] << 4) | j[1]


SERVO_NAME = [
    'LF0',
    'LF1',
    'LF2',

    'RF0',
    'RF1',
    'RF2',

    'RB0',
    'RB1',
    'RB2',

    'LB0',
    'LB1',
    'LB2',
]
