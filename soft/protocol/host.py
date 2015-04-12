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

seri = serial.Serial('/dev/ttyACM1', 9600)

time.sleep(3)

#(sync, cls, id, len, pcls, pid, check) = struct.unpack('=hccccch', msg)

m = struct.pack('<BBBBB', 0, 0, 2, 5, 5)
msg = struct.pack('<HBBBBBH', 0xA572, 0, 0, 2, 5, 5, check(m))

seri.write(msg);

res = seri.read(5)
print(res)
