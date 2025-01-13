
def func(a,b):
    return f'{b},{a}!'

func("World","Hello") #Hello,World!
func(b="World",a="Hello")#World,Hello!
def func(c,a="World",b="Hello"):
    return f'{b},{a}!{c}?'

func("Anybody")
def proc(*args):
    std=1
    for i in args:
        std*=i
    return std

proc(1,2,3,4,5,6,7,8,9,10) #3628800

def iters(**kwargs):
    for key, value in kwargs.items():
        print(f"{key}: {value}")

iters(age=18,name="CFIT")
"""
age: 18
name: CFIT
"""