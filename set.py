import os
os.system('cls | clear')
print("heool")

setA = set()
setB = set()
 
n = int(input("Enter size : "))
m = int(input("Enter size : "))

for i in range(n):
    ele = int(input("Enter : "))
    setA.add(ele)

for i in range(m):
    ele = int(input("Enter : "))
    setB.add(ele)

size = len(setA)
dele = int(input("Enter what to dlelte :"))
setA.remove(dele)

search = int(input("Enter what to search : "))
if search in setA:
    print("true")
else:
    print("false")

print(setA)

setc = setA - setB
setd = setA & setB
sete = setA | setB

print("differece : " , setc)
print("and : ", setd)
print("or: ", sete)

if(setA.issubset(setB)):
    print("yes is subset")