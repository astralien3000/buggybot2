import serial
import time
import sys
import struct
import socket
import threading
from mod.calib import *
from lib.protocol import *


def dump(msg):
    for c in msg:
        print ord(c)


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
                if self.handlers.has_key((cls, id)):
                    pak = self.handlers[(cls, id)][0]()
                    pak.unpack(data[0:7+self.msg_length])
                    self.handlers[(cls, id)][1](pak)
                self.state = 'SYNC'
                self.data = self.data[7+self.msg_length:]
                

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
        time.sleep(0.1)
        data = seri.read(seri.inWaiting())
        parser.parse(data)

def send_cmd(seri, sid, val):
    msg = ServoPWM()
    msg['id'] = SERVO[sid]
    msg['pwm'] = int(val)
    seri.write(msg.pack())
    time.sleep(0.1)
    data = seri.read(seri.inWaiting())
    parser.parse(data)
    time.sleep(0.1)
    
def reset_default(seri):
    for sid in SERVO_CFG.keys():
        send_cmd(seri, sid, SERVO_CFG[sid][0])

def test_bumper(pak):
    print pak['mask']

def test_gp2(pak):
    print pak['mask']

def test_ack(pak):
    print 'ACK', pak['cls'], pak['id']

def test_nak(pak):
    print 'NAK'

def test_config(pak):
    for k in pak.data.keys():
        print str(k), ' = ', str(pak[k])


seri = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(3)

parser = Parser()
parser.addHandler(GP2, test_gp2)
parser.addHandler(Bumper, test_bumper)
parser.addHandler(ServoConfig, test_config)
parser.addHandler(Ack, test_ack)
parser.addHandler(Nak, test_nak)

serv = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)
serv.bind(('/tmp/buggybot2'))

configure_servos(seri)
reset_default(seri)

msg = ServosCtrl()
for k in msg.keys:
    msg[k] = 0
msg['lf2'] = int(90)
dump(msg.pack())
seri.write(msg.pack())

while True:
    data = serv.recv(100)
    if data:
        seri.write(data)
        #time.sleep(0.00001)
        seri.read(seri.inWaiting())


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
