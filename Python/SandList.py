k=int(input("Type the odd number : "))

SandList=list(range(k,0,-2))
SandList+=list(range(3,k+1,2))
print(SandList)
for sand in SandList:
    print("-"*((k-sand)//2),end="")
    for i in range(sand):
        if(i%2==0):
            print("*",end="")
        else:
            print("+",end="")
    print("-"*((k-sand)//2))
