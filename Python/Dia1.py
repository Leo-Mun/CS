k=int(input("Type the odd number : "))

for i in range(1,(k+1)//2):
    for j in range(k//2,i-1,-1):
        print('*',end='')
    for j in range(1,2*i):
        print('+',end='')
    for j in range(k//2,i-1,-1):
        print('*',end='')
    print()
print('+'*k)
for i in range(((k+1)//2)-1,0,-1):
    for j in range(k//2,i-1,-1):
        print('*',end='')
    for j in range(1,2*i):
        print('+',end='')
    for j in range(k//2,i-1,-1):
        print('*',end='')
    print() 
