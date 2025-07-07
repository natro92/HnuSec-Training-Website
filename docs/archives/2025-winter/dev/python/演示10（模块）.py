import time #这些是系统内置库
print(time.time())
time.sleep(2)
print(time.time())
import random
print(random.randint(0,1<<32))
import json
dic={a:b**2 for a,b in zip(range(1,10),range(9,0,-1))}
print(json.dumps(dic))

import requests # 第三方库，需要pip安装
a=requests.get("https://cfitsec.cn/").content.decode('utf-8')
print(a)

import mod
print(mod.random()) #引入自定义模块
import mod as m #可配置自定义名称
print(m.random())
from mod import * #这样可以直接引入函数，还可以写成from mod import random来引入专门的函数
print(random())