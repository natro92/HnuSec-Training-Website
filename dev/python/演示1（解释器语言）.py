import time #time库，用于暂停程序数秒
i=1 #i为1
print(i)#输出i
time.sleep(5)#等5s
def c():#函数a
    print(1//0)#错误，1除以0

def b():#函数b
    c()

def a():#函数c
    b()

a()