list = [6, 7, 5, 3, 1]

##for i in range(len(list)):
##    for j in range(len(list)-1):
##        if list[j]> list[j+1]:
##            list[j], list[j+1] = list[j+1], list[j]
##
##print(list)
small = list[0]
for i in range(len(list)-1):
    if small >= list[i+1]:
        small=list[i+1]
        
print(small)
