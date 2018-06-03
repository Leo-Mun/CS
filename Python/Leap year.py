year = int(input("Type the number of year : "))


if year %400 ==0 or year %4 ==0 and (not(year %100 ==0)):
           print("%d is a leap year." %year)
else :
    print("%d is not a leap year." %year)
