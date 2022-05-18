from array import *


    
def insert(a,max):
    print("Inside Insert")
    ans = 1
    cnt = 0
    while ans == 1:
        key = int(input("Enter Phone Number : "))
        loc = key % max
        flag = 0
        step = 0
        while flag == 0 and cnt < max :
            loc_n = (loc + (step * step)) % max
            if(a[loc_n] == -1): 
                a[loc_n] = key
                flag = 1
                cnt +=1 
                break
            else:
                step += 1
        ans = int(input("Add another phone number : "))

def display(a):
    print("Inside Display")
    sn = 0
    for i in a :
        print(sn," -- ", i)
        sn +=1

def linear(a,max):
    print("Inside Linear")
    target = int(input("Enter a phone number to Search : "))
    index = target%max
    flag = 0
    while a[index] != -1:
        if(a[index] == target):
            print("Entered Phone Number Found on index : ", index)
            break
        else:
            index += 1
            index = index%max
        
    if a[index] == -1:
        print("Entered Number not Found ")


def quad(a,max):
    print("Inside Quad")
    target = int(input("Enter a Phone number to Search : "))
    index = target%max
    step = 0
    while a[index] != -1:
        loc = (index + (step*step))%max
        if(a[loc] == target):
            print("Entered Phone Number found on index : " , loc)
            break
        else:
            print(loc)
            step +=1
    if a[loc] == -1:
        print("Entered Number Not found ")
    



def main():
    max = 10 #sizeof hash 
    a = array('i',[-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,])
    sn = 0
    print("Initial Phone book :")
    for i in a:
        print(sn, " -- ", i)
        sn += 1
    

    print("1: Insert in Phone book")
    print("2: Display Phone book")
    print("3: Search Using linear probing")
    print("4: Search Using Quadratic probing")
    print("5: EXIT")

    while True:
        choice = int(input("Enter you choice : "))
        if choice == 1:
            insert(a,max)
        elif choice == 2:
            display(a)
        elif choice == 3:
            linear(a,max)
        elif choice == 4:
            quad(a,max)
        elif choice == 5:
            print("PROGRAM END")
            break
        else:
            print("Please Enter a valid option")


    

main()