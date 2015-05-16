import socket
import time

time.sleep(20)

cli = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
cli.connect(('127.0.0.1', 54000))
cli.send('aa')
