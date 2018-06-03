year = int(input("Type the number of year : "))
month = int(input("Type the number of month : "))
day = int(input("Type the number of day : "))
days = 0

for i in range(1, year):
    if i %400 ==0 or i %4==0 and (not(i%100==0)):
        days += 366
    else :
        days += 365

print("days", days)

for j in range(1, month):
    if j == 1 :
        days += 31
    elif j==2:
        if year %400==0 or year %4 ==0 and (not(year%100==0)):
            days += 29
        else :
            days += 28
    elif j ==3:
        days +=31
    elif j==5:
        days += 31
    elif j==7:
        days += 31
    elif j==8:
        days+= 31
    elif j==10:
        days+= 31
    elif j==12:
        days+= 31
    else :
        days+=30

print("days", days)

days += day

weekday = days
if days %7 ==0:
    print("It is Sunday.")
if days %7 ==1:
    print("It is Monday.")
if days %7 ==2:
    print("It is Tuesday.")
if days %7 ==3:
    print("It is Wednesday.")
if days %7 ==4:
    print("It is Thursday.")
if days %7 ==5:
    print("It is Friday.")
if days %7 ==6:
    print("It is Saturday.")
