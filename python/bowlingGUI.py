import tkinter as tk
root = tk.Tk()
root.title('Bowling Score')
root.geometry('400x200')


class Window:

    def __init__(self, master):
        #myFrame = Frame(master)
        #myFrame.pack()
        self.bowler_list = []
        self.menubar = tk.Frame(master)
        menubar_x = 0
        self.framebar = tk.LabelFrame(master, text = "frame")

#============ menu bar =========

        self.add_player = tk.Button(self.menubar, text = 'Add Player', command = self.add_player)
        self.print_frame = tk.Button(self.menubar, text = 'Print Game', command = self.frame_button)
        self.quit = tk.Button(self.menubar, text = 'Quit', command = self.quit)

#===============================

        self.event = tk.Label(master, text = '', padx = 60)
        self.type = tk.Entry(master)

        self.menubar.grid(row = 0, column = 0)
        self.add_player.grid(row = menubar_x, column = 0)
        self.print_frame.grid(row = menubar_x, column = 1)
        self.quit.grid(row = menubar_x, column = 2)
        self.framebar.grid(row = 2, column = 0)


        self.type.grid(row = 1, column = 0)
        self.event.grid(row = 1, column = 1)

    def add_player(self):
        print ('bowler entered')

        if (self.type.get() == ''):                     #entry empty
            print ('no bowler entered')
            self.event.configure(text = 'error')


        else:
            self.event.configure(text = self.type.get())
            self.bowler_list.append(self.type.get())    #add bowler to bowler list
            print (self.bowler_list)                    #print bowler name
            self.type.delete(0, 'end')                  #clear entry after add player is clicked


            bowler_num = 0

            self.bowler_list[bowler_num] = tk.Label(self.framebar, text = self.type.get())
            self.bowler_list[bowler_num].grid(row = bowler_num, column = 0)
            bowler_num += 1


    def frame_button(self):
        print(game1.frames)

    def quit(self):
        exit()

class Bowler:                   #adds bowler name and frame dynamically
    def __init__(self, name):
        self.name = name          #name on the right is the paramenter in method



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
        if (1 <= self <= 9):                             #first roll not stike
            framepoints = []
            framepoints.append(bowlpoint1)
            bowlpoint2 = int(input('second roll >> '))
            framepoints.append(bowlpoint2)
            game1.frames.append(framepoints)

            if (i == 10 and (framepoints[0] + framepoints[1] == 10)):
                bowlpoints3 = int(input('third roll >> '))
                framepoints.append(bowlpoints3)
                                                        # check if result is spare or strike
        elif (self == 10):                               #first roll strike
            framepoints = []
            framepoints.append(bowlpoint1)
            game1.frames.append(framepoints)

            if (i == 10):
                bowlpoints2 = int(input('second roll >> '))
                framepoints.append(bowlpoints2)

                if (i == 10):
                    bowlpoints3 = int(input('third roll >> '))
                    framepoints.append(bowlpoints3)

window = Window(root)
bowler1 = Bowler('Leighton')
game1 = Game()
game1.start()
#print(game1.frames)

root.mainloop()
