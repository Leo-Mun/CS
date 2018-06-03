k = int(input("Type the odd number : "))

for i in range(1, k+1):
    for j in range(1, i+1):
        print(i, end=' ')
        i+=k-j
    print()
