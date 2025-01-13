class A:
    pass    # 定义了一个空类

A.b = 1       # 为 A 添加类公有成员变量 b

c = A()       # 实例化
print(c.b)          # 1

c.b = 3

print(c.b)          # 3
print(A.b) # 1
print(c.__class__.b)    # 1

class B:
    def __init__(self, a, b):
        self.a = a
        self.__b = b #私有成员
    def out(self):
        print(self.a, self.__b)

a = B(1, 2)
print(a.a)      # 1
print(a.__b)    # AttributeError: 'B' object has no attribute '__b'
a.out()           # 1 2