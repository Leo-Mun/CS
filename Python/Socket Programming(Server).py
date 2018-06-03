import socket

import sys
sys.path.append("C:/Users/Moon/Desktop/Python/소스코드")

import Password

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(('',8888))
s.listen(1)
print('Socket Listen Start')

connector, addr = s.accept()

while 1 :
    
    data = connector.recv(1024)
    if not data : break

    key='123'
    
    Password.string_xor('data', 'key')
    
    
    print("Received Message : ", data.decode('utf-8'))

    data = input("Message : ")
    connector.send(data.encode('utf-8'))

s.close()
