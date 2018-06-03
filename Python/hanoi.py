import turtle

class Disc(turtle.Turtle):
    def __init__(self, n):
        turtle.Turtle.__init__(self, shape="square", visible=False)
        self.penup()
        self.sety(100)
        self.shapesize(1.5, n*1.5, 2)
        self.fillcolor(n/6., 0, 1-n/6.)
        self.showturtle()

class Tower(list):   
    def __init__(self, x):
        self.x = x
        t = turtle.Turtle()
        t.hideturtle()
        t.penup()
        t.shape('square')
        t.setpos(self.x, -60)        
        t.shapesize(10, 1, 2)
        t.fillcolor('blue')
        t.showturtle()
        self.t = t
        
    def push(self, d):
        d.setx(self.x)
        d.sety(-150+34*len(self))
        self.append(d)
        
    def pop(self):
        d = list.pop(self)
        d.sety(150)
        return d

def hanoi(n, from_, to_, with_):
    if n>0:
        hanoi(n-1, from_, with_, to_)
        to_.push(from_.pop())
        hanoi(n-1, with_, to_, from_)

s = turtle.Screen()

t1 = Tower(-250)
t2 = Tower(0)
t3 = Tower(250)

for i in range(6,0,-1):
    t1.push(Disc(i))


hanoi(6,t1,t3,t2)

