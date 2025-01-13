i=0
print(i)
i=5
print(i)

if(i!=5):
    print("Error")
elif(i!=0)
    print("呀哈哈!")
else:
    print("???")

while(i<10):
    print(i)
    i=i+1

for i in range(1,11):
    print(i,end=",")

for i in range(1,11,2):
    print(i,end=",")

for i in range(11,1,-2):
    print(i,end=",")

for i in [1,2,3,5,8]:
    print(i,end=",")

for i in "CFIT":
    print(i,end=",")

#拓展
for i,j in enumerate("CFIT"):
    print(i,j)
