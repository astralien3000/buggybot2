import socket
import serial
import os
import sys
import re
import time

def get_available_serials():
    l = os.listdir('/dev')
    ret = []
    for d in l:
        if re.search('^ttyACM\d+$', d) != None:
            ret.append('/dev/'+d)
    return ret


SERVER_SOCK='/tmp/buggybot2'
SERIAL_BAUDRATE = 9600

while True:
    serials = []
    while serials == []:
        print 'Searching serial port...'
        serials = get_available_serials()
        if serials == []:
            time.sleep(0.5)
    seri = serial.Serial(serials[0], SERIAL_BAUDRATE)

    if os.path.exists(SERVER_SOCK):
        os.remove(SERVER_SOCK)
    
    serv = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)
    serv.bind(SERVER_SOCK)

    try:
        time.sleep(3)
        seri.write(b'main\n')
        while True:
            data = serv.recv(1024)
            sys.stdout.write(data)
            seri.write(data)
    except serial.SerialException as e:
        print e

    serv.close()
    seri.close()
