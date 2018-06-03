a=[8,4,9,5]
small = a[0]
for i in range(0, len(a)-1):
    if small>=a[i+1]:
        small=a[i+1]
print(small)
