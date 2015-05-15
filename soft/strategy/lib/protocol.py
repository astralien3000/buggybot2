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
    def __getitem__(self, key):
        return self.data[key]
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
    def unpack(self, data):
        format = ''
        for k in self.keys:
            format += self.data[k][0]
        format += 'H'
        res = struct.unpack('<'+format, data[5:])
        for i in range(0, len(self.keys)):
            self.data[self.keys[i]] = res[i]
        

class Protocol(Message):
    def __init__(self):
        Message.__init__(self)
        self.cls = 0

class Ack(Protocol):
    def __init__(self):
        Protocol.__init__(self)
        self.id = 0
        self.addField(Type.U8, 'cls')
        self.addField(Type.U8, 'id')

class Nak(Protocol):
    def __init__(self):
        Protocol.__init__(self)
        self.id = 1
        self.addPollField(Type.U8, 'dummy')

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
        self.id = 0
        self.addPollField(Type.U8, 'id')
        self.addField(Type.S16, 'angle')

class Config(Message):
    def __init__(self):
        Message.__init__(self)
        self.cls = 1

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

class SaveConfig(Config):
    def __init__(self):
        Config.__init__(self)
        self.id = 0
        self.addPollField(Type.U8, 'dummy')

class Buggybot(Message):
    def __init__(self):
        Message.__init__(self)
        self.cls = 4

class ServosCtrl(Buggybot):
    def __init__(self):
        Buggybot.__init__(self)
        self.id = 0
        self.addField(Type.S16, 'lf0')
        self.addField(Type.S16, 'lf1')
        self.addField(Type.S16, 'lf2')
        self.addField(Type.S16, 'rf0')
        self.addField(Type.S16, 'rf1')
        self.addField(Type.S16, 'rf2')
        self.addField(Type.S16, 'rb0')
        self.addField(Type.S16, 'rb1')
        self.addField(Type.S16, 'rb2')
        self.addField(Type.S16, 'lb0')
        self.addField(Type.S16, 'lb1')
        self.addField(Type.S16, 'lb2')


class Protocol(Message):
    def __init__(self):
        Message.__init__(self)
        self.cls = 0

class Ack(Protocol):
    def __init__(self):
        Protocol.__init__(self)
        self.id = 0
        self.addField(Type.U8, 'cls')
        self.addField(Type.U8, 'id')

class Nak(Protocol):
    def __init__(self):
        Protocol.__init__(self)
        self.id = 1
        self.addPollField(Type.U8, 'dummy')

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
        self.cls = 1

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

class SaveConfig(Config):
    def __init__(self):
        Config.__init__(self)
        self.id = 0
        self.addPollField(Type.U8, 'dummy')

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

class GP2(Sensor):
    def __init__(self):
        Sensor.__init__(self)
        self.id = 1
        self.addPollField(Type.U8, 'id')
        self.addField(Type.U16, 'value')


class Parser:
    def __init__(self):
        self.handlers = dict()
        self.data = ''
        self.state = 'SYNC'
        self.msg_length = None
        self.MAX_BUFFER_SIZE = 64
    def addHandler(self, msg, func):
        m = msg()
        self.handlers[(m.cls, m.id)] = (msg, func)
    def parse(self, data):
        wait_data = False
        self.data += data
        while not wait_data:
            if self.state == 'SYNC':
                #print 'SYNC'
                if len(self.data) < 2:
                    wait_data = True
                else:
                    (sync,) = struct.unpack('<H', self.data[0:2])
                    if sync == Message.sync:
                        self.state = 'LENGTH'
                    else:
                        self.data = self.data[1:]
            elif self.state == 'LENGTH':
                #print 'LENGTH'
                if len(self.data) < 5:
                    wait_data = True
                else:
                    (length,) = struct.unpack('<B', self.data[4:5])
                    if length < self.MAX_BUFFER_SIZE:
                        self.state = 'CHECK'
                        self.msg_length = length
                    else:
                        self.state = 'SYNC'
                        self.data = self.data[1:]
            elif self.state == 'CHECK':
                #print 'CHECK'
                length = 7 + self.msg_length
                if len(self.data) < length:
                    wait_data = True
                else:
                    chk1 = check(self.data[2:length-2])
                    (chk2,) = struct.unpack('<H', self.data[length-2:length])
                    if chk1 == chk2:
                        self.state = 'PREDICATE'
                    else:
                        self.state = 'SYNC'
                        self.data = self.data[1:]
            elif self.state == 'PREDICATE':
                #print 'PREDICATE'
                (cls, id) = struct.unpack('<BB', self.data[2:4])
                #print cls, id
                if self.handlers.has_key((cls, id)):
                    print 'OK'
                    pak = self.handlers[(cls, id)][0]()
                    pak.unpack(data[0:7+self.msg_length])
                    self.handlers[(cls, id)][1](pak)
                self.state = 'SYNC'
                self.data = self.data[7+self.msg_length:]

