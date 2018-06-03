list = [1 , 5, 7, 2, 9]

for i in range(len(list)):
    for j in range(len(list)-1):
        if list[j]> list[j+1]:
            list[j], list[j+1] = list[j+1], list[j]

print(list)
