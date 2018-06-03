a = input()
b = input()
s = int(input())

def sum (a, b, s) :
    if s == 0 :
        return int(a)+int(b)

    if s != 0 :
        return a + b

print(sum(a, b, s))
