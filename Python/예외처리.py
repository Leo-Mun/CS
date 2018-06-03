##def divide(m, n):
##    try:
##        result = m/n
##    except ZeroDivisionError:
##        print("0으로 나눌 수 없습니다.")
##    except :
##        pritn("ZeroDivisionError 이외의 예외 발생")
##    else :
##        return result
##    finally :
##        print("나눗셈 연산")
##
##res = divide(3,2)
##print(res)
##res = divide(10,0)
##print(res)
##res = divide(200,3)
##print(res)
##

try :
    f = open('abc', 'r')
except FileNotFoundError :
    print('File not exist')
finally :
    print('Failed to open a file')
