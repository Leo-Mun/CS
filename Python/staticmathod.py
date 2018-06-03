class Ball :
    instCount = 0
    def __init__(self):
        Ball.instCount +=1

    def getInstCount():
        return Ball.instCount

    def __del__(self):
        Ball.instCount -=1

        
##    color= 'red'
##    size = 'small'
##    
##    def getColor(self):
##        return self.color
##
##    def getSize():
##        return 'medium'

myBall = Ball()
newBall = Ball()
print(Ball.getInstCount())
##print(Ball.getSize())
