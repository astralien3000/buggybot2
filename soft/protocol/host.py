import serial
import time
import sys
import struct

def check(buff):
    chk0 = 0
    chk1 = 0
    for c in buff:
        chk1 = (chk1 + chk0) % 256
        chk0 = (chk0 + ord(c)) % 256
    return chk1 << 8 | chk0

class Type:
    U8 = 'B'
    U16 = 'H'
    U32 = 'Q'
    S8 = 'b'
    S16 = 'h'
    S32 = 'q'
    SIZE = {
        U8 : 1,
        U16 : 2,
        U32 : 4,
        S8 : 1,
        S16 : 2,
        S32 : 4,
    }

class Message:
    sync = 0xA572
    def __init__(self):
        self.data = dict()
        self.poll = []
        self.keys = []
        self.cls = None
        self.id = None
    def addField(self, type, name):
        self.data[name] = (type, None)
        self.keys.append(name)
    def addPollField(self, type, name):
        self.addField(type, name)
        self.poll.append(name)
    def __setitem__(self, key, val):
        it = self.data[key]
        self.data[key] = (it[0], val)
    def pollRequest(self):
        self.keys = self.poll
    def pack(self):
        format = 'BBB'
        args = [self.cls, self.id]
        tmp = []
        len = 0
        for k in self.keys:
            format += self.data[k][0]
            len += Type.SIZE[self.data[k][0]]
            tmp.append(self.data[k][1])
        args += [len] + tmp
        chk = check(struct.pack('<' + format, *args))
        args = [Message.sync] + args + [chk]
        format = Type.U16 + format + Type.U16
        ret = struct.pack('<' + format, *args)
        return ret

class Protocol(Message):
    def __init__(self):
        Message.__init__(self)
        self.cls = 0

class Ack(Protocol):
    def __init__(self):
        Protocol.__init__(self)
        self.id = 0x00
        self.addField(Type.U8, 'cls')
        self.addField(Type.U8, 'id')

class Actuator(Message):
    def __init__(self):
        Message.__init__(self)
        self.cls = 2

class ServoPWM(Actuator):
    def __init__(self):
        Actuator.__init__(self)
        self.id = 1
        self.addPollField(Type.U8, 'id')
        self.addField(Type.U16, 'pwm')

class ServoAngle(Actuator):
    def __init__(self):
        Actuator.__init__(self)
        self.id = 1
        self.addPollField(Type.U8, 'id')
        self.addField(Type.S16, 'angle')

class Config(Message):
    def __init__(self):
        Message.__init__(self)
        self.cls = 0

class ServoConfig(Config):
    def __init__(self):
        Config.__init__(self)
        self.id = 1
        self.addPollField(Type.U8, 'id')
        self.addField(Type.U16, 'default_pwm')
        self.addField(Type.S16, 'angle1')
        self.addField(Type.U16, 'angle1_pwm')
        self.addField(Type.S16, 'angle2')
        self.addField(Type.U16, 'angle2_pwm')

class Sensor(Message):
    def __init__(self):
        Message.__init__(self)
        self.cls = 3

class Bumper(Sensor):
    def __init__(self):
        Sensor.__init__(self)
        self.id = 0
        self.addPollField(Type.U8, 'id')
        self.addField(Type.U16, 'mask')


def dump(msg):
    for c in msg:
        print ord(c)


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

SERVO_CFG = {
    'LF0' : (44, 0, 92, 90),
    'LF1' : (73, 0, 121, 90),
    'LF2' : (30, 0, 118, 180),

    'RF0' : (112, 0, 60, 90),
    'RF1' : (81, 0, 132, 90),
    'RF2' : (38, 0, 126, 180),

    'RB0' : (50, 0, 102, 90),
    'RB1' : (100, 0, 44, 90),
    'RB2' : (130, 0, 38, 180),

    'LB0' : (105, 0, 56, 90),
    'LB1' : (74, 0, 130, 90),
    'LB2' : (32, 0, 122, 180),
}

def create_config_msg(sid):
    ret = ServoConfig()
    ret['id'] = SERVO[sid]
    cfg =  SERVO_CFG[sid]
    ret['default_pwm'] = cfg[0]
    ret['angle1'] = cfg[1]
    ret['angle1_pwm'] = cfg[0]
    ret['angle2'] = cfg[3]
    ret['angle2_pwm'] = cfg[2]
    return ret

def configure_servos(seri):
    for sid in SERVO_CFG.keys():
        msg = create_config_msg(sid)
        seri.write(msg.pack())
        time.sleep(0.001)
    
seri = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(3)

while True:
    bum = Bumper()
    bum['id'] = 0
    bum.pollRequest()
    seri.write(bum.pack())
    res = seri.read(10)
    print '--> RES'
    dump(res)
    time.sleep(5)
    

#san = ServoAngle()
#san['id'] = SERVO['LF1']

# configure_servos(seri)
# time.sleep(0.5)

# san['angle'] = 90
# seri.write(san.pack())
# time.sleep(2)

# san['angle'] = 0
# seri.write(san.pack())
# time.sleep(0.5)

#seri.write(mm2)
#time.sleep(1)
