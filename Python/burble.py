a=[12,8,4,9,5]

import time
import random

low = 0
high = 100000
iter = 1000
a=[]
for i in range(iter):
    a.append(random. randint(low, high))

b= a[:]

start = time.time()
b.sort()
end=time.time()

print('running sort', iter, 'takes', end-start)

start=time.time()

for i in range(len(a)-1):
    for j in range(len(a)-1-i):
        if(a[j]>a[j+1]):
            tmp=a[j]
            a[j]=a[j+1]
            a[j+1]=tmp
end=time.time()

print('running sort', iter, 'takes', end-start)
