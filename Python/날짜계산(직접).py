year = int(input("Type the number of year : "))
month = int(input("Type the number of month : "))
day = int(input("Type the number of day : "))
days = 0
for i in range(1, year):
    if i%400==0 or i%4==0 and (not(i%100==0)):
        days +=366
    else :
        days += 365

print('days', days)
for i in range(1,month):
    if i == 1:
        day += 31
    elif i ==2 :
        if year%400==0 or year%4==0 and (not(year%100==0)):
            day += 29
        else :
            day +=28
    elif i == 3 :
        day +=31
    elif i ==5 :
        day +=31
    elif i == 7:
        day += 31
    elif i== 8 :
        day += 31
    elif i == 10 :
        day += 31
    else :
        day +=30
print('days', days)
days += day
print('days', days)
weekday= days%7
if weekday ==0 :
    print("It is Sunday")
if weekday ==1 :
    print("It is Monday")
if weekday ==2 :
    print("It is Tuesday")
if weekday ==3 :
    print("It is Wednesday")
if weekday ==4 :
    print("It is Thursday")
if weekday ==5 :
    print("It is Friday")
if weekday ==6 :
    print("It is Saturday")

year = int(input('년도를 입력하세요 : '))
month = int(input('몇 월인지 입력하세요 : '))
day = int(input('며칠인지 입력하세요 : '))

print(year,',',month,',',day)

#compute a number of days
days = 0

##compute a number of days according a year
for i in range(1,year) :
    if i%400==0 or i%4==0 and i%100 != 0 :
        days += 366
    else :
        days += 365

print('days', days)
##compute a number of days according a month
for i in range(1,month) :
    if i == 1 :
        days += 31
    elif i == 2 :
        if year%400==0 or year%4==0 and year%100 != 0:
            days += 29
        else :
            days += 28
    elif i == 3 :
        days += 31    
    elif i == 5 :
        days += 31
    elif i == 7 :
        days += 31
    elif i == 8 :
        days += 31
    elif i == 10 :
        days += 31
    else :
        days += 30

print('days', days)

##compute a number of days according a rest days
days += day

print('days', days)

#compute a weekday
weekday = days % 7

if weekday == 1 :
    print('월요일 입니다.')
if weekday == 2 :
    print('화요일 입니다.')
if weekday == 3 :
    print('수요일 입니다.')
if weekday == 4 :
    print('목요일 입니다.')
if weekday == 5 :
    print('금요일 입니다.')
if weekday == 6 :
    print('토요일 입니다.')
if weekday == 0 :
    print('일요일 입니다.')

