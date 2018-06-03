k=int(input("Type the odd number : "))

center = k//2
a=1

for i in range(k):
    b=(k-a)//2
    print('*'*b,'+'*a,'*'*b)
    if i <center:
        a+=2
    else:
        a-=2
