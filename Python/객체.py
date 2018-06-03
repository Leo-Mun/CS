class Ball :
    
    def __init__(self,color, size,direction):
        self.color=color
        self.size=size
        self.direction=direction
        print('Ball is constructed.')

    def __del__(self):
        print('Ball is deleted.')

    def __str__(self):
        msg = 'color : '+ self.color+ ' size : ' + self.size
        return msg

myBall = Ball(' red' , ' small' , 'stop')
print(myBall)
myBall=Ball('blue','large','stop')
