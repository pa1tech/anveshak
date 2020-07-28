# Control Signals over Ethernet  
  * A client server environment is created using socket programming
  * Protocol used - TCP/IP
  * General working of client server environment: [Client Server](https://files.realpython.com/media/sockets-tcp-flow.1da426797e37.jpg)

### Eg. Code for server:
```
import socket

HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
PORT = 65432        # Port to listen on (non-privileged ports are > 1023)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print('Connected by', addr)
        while True:
            data = conn.recv(1024)
            if not data:
                break
            conn.sendall(data)
```
### Eg. Code for client
```
import socket

HOST = '127.0.0.1'  # The server's hostname or IP address
PORT = 65432        # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b'Hello, world')
    data = s.recv(1024)
```
### Links:
  * Socket programming:[https://realpython.com/python-sockets/](https://realpython.com/python-sockets/)
  * TCP/IP:[https://www.geeksforgeeks.org/tcp-ip-model/](https://www.geeksforgeeks.org/tcp-ip-model/)


      
