a = int(input("row : "))
b = int(input("column : "))
c = int(input("block : "))

for m in range(1, c+1):
    for i in range(1, a+1):
        for j in range(1, b+1):
            print('*', end='')
        print()
    print()
