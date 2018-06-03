### Define a function
##def f1():
##    print("f1 starts")
##    f2()
##    print("f1 ends")
##
##def f2():
##    print("f2 starts")
##    f3()
##    print("f2 ends")
##
##def f3() :
##    print("f3 starts")
##    print("f3 ends")
##
### main program
##print("Program starts")
##f1()
##print("program ends")

##def printmyaddress(firstname, lastname, roomnum):
##    print(firstname, lastname)
##    print("Room #", roomnum)
##    print("Kookmin Univ., South Korea")
##
##printmyaddress("M", "Yoon", 616)
##printmyaddress("S", "Yoon", 717)
##printmyaddress("K", "Hong", 777)

##def printperson(name, num):
##    name = "S Lee"
##    num = 618
##    print("In the func. : ", name, num)
##
##pName = "M Yoon"
##pNum = 616
##print("before the func. : "

def calculateTax(price, tax_rate) :
    total = price + (price*tax_rate)
    return total

my_price = float(input("Enter a price : "))

totalPrice = calculateTax(my_price, 0.06)

print("price = ", my_price, "Total price = ", totalPrice)
