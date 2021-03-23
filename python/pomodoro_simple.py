import time

def timer(minutes):
    minutes *= 60
    while minutes >= 0:
        min, sec = divmod(minutes, 60)
        countdown = ("[" + str(min).zfill(2) + ":" + str(sec).zfill(2) + "]")
        print (countdown + "\r", end = "")
        time.sleep(1)
        minutes -= 1

while True:
    userInput = int(input("""
________________________________________
|           [Pomodoro Timer]           |
|   [1] 25 mins work and 5 mins break  |
|   [2] 50 mins work and 10 mins break |
|   [3] Custom time                    |
|   [0] to quit                        |
|______________________________________|

>> """))

    #print ("\n")
    if (userInput == 1):
        try:
            timer(25)
            print ("[BREAK TIME]")
            userInput = input("press [enter] to start Break")
            timer(5)

        except KeyboardInterrupt:
            pass

    elif (userInput == 2):
        try:
            timer(50)
            print ("[BREAK TIME]")
            userInput = input("press [enter] to start Break")
            timer(10)

        except KeyboardInterrupt:
            pass

    elif (userInput == 3):
        userInput = int(input("Enter work minutes\n>> "))
        minW = userInput
        userInput = int(input("Enter break minutes\n>> "))
        minB = userInput

        try:
            timer(minW)
            print ("[BREAK TIME]")
            userInput = input("press [enter] to start Break")
            timer(minB)

        except KeyboardInterrupt:
            pass

    elif (userInput == 0):
        print ("Quit")
        exit()
