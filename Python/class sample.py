class Ball :
    def __init__(self, color, size, direction):
        self.color=color
        self.size=size
        self.direction=direction


    def __del__(self):
        print('class deleted')

    def __str__(self):
        return self.color + ' ' + self.size
        
myBall = Ball("red","small","down")
print(myBall)

##newBall=Ball('blue','medium','up')
##print(newBall.color,newBall.size,newBall.direction)

myBall = Ball('blue','large','stop')
print(myBall)

