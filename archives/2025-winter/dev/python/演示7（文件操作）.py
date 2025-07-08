with open("flag","r") as f:
    print(f.read()) #返回所有

with open("flag","r") as f:
    print(f.readline()) # 返回一行

with open("flag","r") as f:
    print(f.readlines()) # 返回一个列表

open("flag","r").read() # 此后学习web(rce)常用的一句话读取

with open("hw.txt","w") as f:
    f.write("Hello World!") # 直接写入文件

with open("hw.txt","a+") as f:
    f.write("Hello HnuSec!") # 在文件末尾追加字符串