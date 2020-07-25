import socket
import time
import main

b='0'

def Main():
	global b

	host = '0.0.0.0'
	port = 8000

	s = socket.socket()
	s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
	s.bind((host,port))

	s.listen(1)
	c, addr = s.accept()
	print "Connection from: " + str(addr)
	
	while True:
		f=open("file.txt", "r")
		b=file.read()
		print "Sending: " + b
		c.send(str(a))
		time.sleep(1)
	c.close()

if __name__ == '__main__':
    Main()

