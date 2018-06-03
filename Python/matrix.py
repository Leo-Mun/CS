import numpy as np

##A = np.mat([ [1,0,0] , [0,1,0] , [0,0,1] ])
##B = np.mat([ [1] , [0] , [0] ])

##print(A)
##print(B)
##
##print(A+A)
##
##print(A-B)
##
##print(A*A)
##
##print(A*B)
##
##print(B-B)
##print(B+B)

A=np.mat([[2,1,1],[3,2,1],[2,1,2]])
inv_A=np.linalg.inv(A)
print(A)
print(inv_A)
print(A*inv_A)
