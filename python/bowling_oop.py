class Game:                 #sets up the game and frame
    def __init__(self):
        self.frames = []

    def start(self):
        global bowlpoint1
        global i
        for i in range(1,11):

            if (1 <= i <= 10):                                      #10 frames game
                print ('frame', i)
                bowlpoint1 = int(input('first roll >> '))
                print (bowlpoint1)
                check = StrikeSpare.checker(bowlpoint1)

class StrikeSpare:      #takes a parameter and check if the parameter is strike or spare
    #add strike spare points to nested list
    def __init__(self, result):
        self.result = result

    def checker(self):                                   #append should be here
        #print (self)
        if (1 <= self <= 9):                             #first roll not stike
            framepoints = []
            framepoints.append(bowlpoint1)
            bowlpoint2 = int(input('second roll >> '))
            framepoints.append(bowlpoint2)
            game1.frames.append(framepoints)

            if (i == 10 and (framepoints[0] + framepoints[1] == 10)):
                bowlpoints3 = int(input('third roll >> '))
                framepoints.append(bowlpoints3)
                #game1.frames.append(framepoints)
                #print (Game().frame)
                                                        # check if result is spare or strike
        elif (self == 10):                               #first roll strike
            framepoints = []
            framepoints.append(bowlpoint1)
            game1.frames.append(framepoints)
            #bowlpoint2 = int(input("second roll >> "))
            #framepoints.append(bowlpoint2)

            if (i == 10):
                bowlpoints2 = int(input('second roll >> '))
                framepoints.append(bowlpoints2)
                #game1.frames.append(framepoints)
                #print (Game().frame)

                if (i == 10):
                    bowlpoints3 = int(input('third roll >> '))
                    framepoints.append(bowlpoints3)
                    #game1.frames.append(framepoints)

class Bowler:
    def __init__(self, name):
        self.name = name            #name on the right is the paramenter in method

bowler1 = Bowler('Leighton')
game1 = Game()
game1.start()
print(game1.frames)
