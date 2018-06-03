b = int(input("Type the number of blocks : "))
r = int(input("Type the number of rows : "))
c = int(input("Type the number of columns : "))
        
for m in range(1, b+1):
    for i in range(1, r+1):
        for j in range(1, c+1):
            print("*", end='')
        print()
    print()
