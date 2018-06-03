a = int(input("Which multiplication table would you like? : "))
b = int(input("how high do you want to go : "))

print("Here's your table : ")
for i in range(1,b+1):
    print(a, "x", i, "=", a*i)

##i=1
##while i <10 :
##    print(a, "x", i, "=", a*i)
##    i+=1
