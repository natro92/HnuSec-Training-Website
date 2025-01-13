try:
    a=1/0
except ZeroDivisionError: #除零错误时执行的代码
    print("Division by zero!")
else: #没有除零错误时执行的代码
    print("No exception!")
finally: #无论是否错误均执行的代码
    print("Finally!")
"""
输出：
Division by zero!
Finally!
"""
try:
    a=1/0
except Exception as e:
    print(f'Error:{e}')
#输出：Error:division by zero