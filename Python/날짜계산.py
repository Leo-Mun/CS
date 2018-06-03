year = int(input('년도를 입력하세요 : '))
month = int(input('몇 월인지 입력하세요 : '))
day = int(input('며칠인지 입력하세요 : '))
def leapyear(year):
    if i%400==0 or i%4==0 and i%100 != 0 :
    
print(year,',',month,',',day)

#compute a number of days
days = 0

##compute a number of days according a year
for i in range(1,year) :
     leapyear(i):
        days += 366
    else :
        days += 365

print('days', days)
##compute a number of days according a month
for i in range(1,month) :
    if i == 1 :
        days += 31
    elif i == 2 :
        leapyear(year) :
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

