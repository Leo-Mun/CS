import socket

import sys
sys.path.append("C:/Users/Moon/Desktop/Python/소스코드")

import Password

HOST = '127.0.0.1'
PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))

while 1 :

    key='123'
    data = input("Message : ")
    
    Password.string_xor('data', 'key')
    s.send(data.encode('utf-8'))

    data = s.recv(1024)
    if not data : break

    
    print("Received Message : ", data.decode('utf-8'))

s.close()

    
