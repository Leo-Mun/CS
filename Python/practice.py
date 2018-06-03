n=1
k=int(input("Type the odd number : "))

##for i in range(1,k+1):
##    for j in range(i):
##        print(n, end=' ')
##        n+=1
##    print()

for i in range(1,k+1):
    print(n,end= ' ')
    n+=1
    for j in range(i):
        print(n+1, end=' ')
        n+=1
