import numpy as np
import matplotlib.pyplot as plt

##data=55+5*np.random.randn(1000)
##
##num_bins = 10
##
##plt.hist(data, num_bins, normed = False)
##plt.show()
labels=['Java','C/C++','Python','JavaScript']
sizes = [35,30,25,10]
colors=['yellowgreen','gold','lightskyblue','lightcoral']
explode=(0,0,0.1,0)

plt.pie(sizes, explode=explode,labels=labels, colors=colors,autopct='%1.1f% %', shadow=True, startangle=90)
plt.axis('equal')
plt.show()
