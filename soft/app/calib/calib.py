from BaseHTTPServer import *

import serial
import time
import sys
import struct
import re

from mod.calib import *

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

def configure_servo(seri, sid):
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

def save_config():
    f = open('mod/calib.py', 'w')
    f.write('from servo import *\n')
    f.write('\n')
    f.write('SERVO_CFG = {\n')
    for k in SERVO_NAME:
        line = '    '
        line += '\'' + k + '\''
        line += ' : '
        line += str(SERVO_CFG[k]) + ',\n'
        f.write(line)
    f.write('}\n')

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
parser.addHandler(ServoConfig, test_config)
parser.addHandler(Ack, test_ack)
parser.addHandler(Nak, test_nak)

configure_servos(seri)
reset_default(seri)

class MyHandler(BaseHTTPRequestHandler):
    def do_HEAD_html(s):
        s.send_response(200)
        s.send_header("Content-type", "text/html")
        s.end_headers()
    def do_HEAD_js(s):
        s.send_response(200)
        s.send_header("Content-type", "text/javascript")
        s.end_headers()
    def do_GET_root(s):
        s.do_HEAD_html()
        s.wfile.write('<head>\n')
        s.wfile.write('<script type="text/javascript" src="client.js">\n')
        s.wfile.write('</script>\n')
        s.wfile.write('</head>\n')
        s.wfile.write('<body>\n')
        s.wfile.write('<table>\n')
        s.wfile.write('<tr>\n')
        s.wfile.write('<td>\n')
        s.wfile.write('<ul class="servo_list">\n')
        for k in SERVO_NAME:
            s.wfile.write('<li><input type="radio" name="servo" value="'+k+'" onclick="servo_select(\''+k+'\')">'+k+'</input></li>\n')
        s.wfile.write('</ul>\n')
        s.wfile.write('</td>\n')
        s.wfile.write('<td>\n')
        s.wfile.write('<div class="servo_config">\n')
        s.wfile.write('<div class="angle_config">\n')
        s.wfile.write('<input type="button" value="<" onclick="dec_p1()"/>\n')
        s.wfile.write('<input type="text" value="0" id="angle1_pwm" onclick="up_p1()" readonly/>\n')
        s.wfile.write('<input type="button" value=">" onclick="inc_p1()"/>\n')
        s.wfile.write(' Angle <span id="angle1">0</span>\n')
        s.wfile.write('</div>\n')
        s.wfile.write('<div class="angle_config">\n')
        s.wfile.write('<input type="button" value="<" onclick="dec_p2()"/>\n')
        s.wfile.write('<input type="text" value="0" id="angle2_pwm" onclick="up_p2()" readonly/>\n')
        s.wfile.write('<input type="button" value=">" onclick="inc_p2()"/>\n')
        s.wfile.write(' Angle <span id="angle2">0</span>\n')
        s.wfile.write('</div>\n')
        s.wfile.write('</div>\n')
        s.wfile.write('</td>\n')
        s.wfile.write('</tr>\n')
        s.wfile.write('</table>\n')
        s.wfile.write('</body>\n')
    def do_GET_servo_cfg(s):
        s.do_HEAD_html()
        s.wfile.write('test')
    def do_GET_client(s):
        s.do_HEAD_js()
        f = open('app/calib/client.js', 'r')
        for l in f:
            s.wfile.write(l)
        f.close()
    def do_GET(s):
        if s.path == '/':
            s.do_GET_root()
        if s.path == '/client.js':
            s.do_GET_client()
        if s.path == '/get_servo_cfg':
            s.do_GET_servo_cfg()
    def do_POST_get_servo_cfg(s):
        l = s.headers['content-length']
        params = s.rfile.read(int(l))
        g = re.search('servo=(.*)', params)
        k =  g.group(1)
        s.do_HEAD_html()
        s.wfile.write('{')
        s.wfile.write('"servo":"'+k+'",')
        s.wfile.write('"default_pwm":'+str(SERVO_CFG[k][0])+",")
        s.wfile.write('"angle1":'+str(SERVO_CFG[k][1])+",")
        s.wfile.write('"angle1_pwm":'+str(SERVO_CFG[k][0])+",")
        s.wfile.write('"angle2":'+str(SERVO_CFG[k][3])+",")
        s.wfile.write('"angle2_pwm":'+str(SERVO_CFG[k][2]))
        s.wfile.write('}')
    def do_POST_set_servo_cfg(s):
        l = s.headers['content-length']
        params = s.rfile.read(int(l)).split('&')
        args = dict()
        for p in params:
            g = re.search('^(.*)=(.*)$', p)
            args[g.group(1)] = g.group(2)
        SERVO_CFG[args['servo']] = (
            int(args['pwm1']),
            int(args['angle1']),
            int(args['pwm2']),
            int(args['angle2']),
        )
        configure_servo(seri, args['servo'])
        save_config()
        s.do_HEAD_html()
        s.wfile.write('OK')        
    def do_POST_servo_cmd(s):
        l = s.headers['content-length']
        params = s.rfile.read(int(l))
        g = re.search('^(.*)=(.*)$', params)
        k =  g.group(1)
        v =  g.group(2)
        send_cmd(seri, k, int(v))
        s.do_HEAD_html()
        s.wfile.write('OK')
    def do_POST(s):
        if s.path == '/get_servo_cfg':
            s.do_POST_get_servo_cfg()
        if s.path == '/set_servo_cfg':
            s.do_POST_set_servo_cfg()
        if s.path == '/servo_cmd':
            s.do_POST_servo_cmd()
        

httpd = HTTPServer(('', 5400), MyHandler)
httpd.serve_forever()
