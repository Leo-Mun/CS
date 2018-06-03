##for i in range(6):
##    print('i=', i)
##    print("Hello, how")
##    if i==3:
##          continue
##    print('are you today?')

##for i in range(6):
##    print('i=', i)
##    print('Hello, how')
##    if i==3:
##        break
##    print('are you today?')

##for i in range(1,10):
##    for j in range(1,10):
##        print(i, "*", j, "=", i*j)
##    print()

##i=2
##while (i<10):
##    j=1
##    while(j<10):
##        print(i, "*", j, '=', i*j)
##        j+=1
##    print()
##    i+=1

##for i in range(10):
##    for j in range(10):
##        print('*', end='')
##    print()

##num=int(input("Type the number of stars : "))
##for multiplier in range(1, num+1):
##    print('*', end='')

b = int(input("Type the number of block : "))
r = int(input("Type the number of rows : "))
c = int(input("Type the number of columns : "))

for b in range(1, b+1):
    for i in range(1, r+1):
        for j in range(1, c+1):
            print('*', end='')
        print()
    print()

