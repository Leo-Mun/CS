k=int(input("Type the odd number : "))

numOfplus = list(range(1, k, 2))
numOfplus += list(range(k, 0, -2))
print(numOfplus)
for plus in numOfplus:
    print("*"*((k-plus)//2), end="")
    print("+"*plus, end="")
    print("*"*((k-plus)//2))
