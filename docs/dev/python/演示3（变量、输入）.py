a=1
print(a)
a="A lot can happen between now and never!"
print(a)
a=r'abcd\nefg'
b=f'123{a}456'
print(a)
print(b)


a=1
b=2.0
c=a+b
print(c)
d="5"
e=d+c #错误,应当强制类型转换
e=float(d)+c
print(e)

a=3
b=2.0
c=5
d=a*b
e=a/b
f=a//b
g=a**c
print(d,e,f,g)
d="Hello HnuSec!"
print(b<a<c) #注意这里相当于b<a and a<c
print(a==3)
print(a is None)
print("Hnu" in d)
print("!" not in d)

a=input("输入一个字符串：")

print(a)
a=int(input("输入一个数字："))

b=2
print(a+b)

