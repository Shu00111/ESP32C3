'''
FilePath: /MAgIC-Fish/3.Software/Testing/py_udp/hz_udp.py
Date: 2023-03-18 13:52:01
LastEditTime: 2023-06-20 18:59:49
LastEditors: Xiaozhu Lin
E-Mail: linxzh@shanghaitech.edu.cn
Institution: MAgIC Lab, ShanghaiTech University, China
'''

from socket import *
from time import ctime
import time

HOST = ''
PORT = 8080
BUFSIZ = 1024
ADDR = (HOST, PORT)
# 192.168.1.105
# 172.20.10.2

udpSerrverSocket=socket(AF_INET,SOCK_DGRAM) # 创建UDP连接
udpSerrverSocket.bind(ADDR) # 绑定服务器地址

while True: # 服务器循环
    udpSerrverSocket.sendto(bytes('hello udp',encoding='utf-8'), ('192.168.1.103', 2333)) # 发送UDP 数据
    # udpSerrverSocket.sendto(bytes('hello udp',encoding='utf-8'), ('192.168.50.222', 58267)) # 发送UDP 数据
    time.sleep(1)
    print("alive!")

udpSerrverSocket.close() # 关闭服务器连接