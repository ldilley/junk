#!/usr/bin/env python

import socket

TCP_IP = '127.0.0.1'
TCP_PORT = 7777
BUFFER_SIZE = 1024

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)
while 1:
  conn, addr = s.accept()
  print 'Connection address:', addr
  data = conn.recv(BUFFER_SIZE)
  if not data: break
  print "Received data:", data
  conn.send(data) # echo
  conn.close()
