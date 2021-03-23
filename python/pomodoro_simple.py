import time

while True:
    userInput = int(input("""
________________________________________
|           [Pomodor Timer]            |
|   [1] to start                       |
|   [2] to stop                        |
|   [0] to exit                        |
|______________________________________|

>> """))

    if (userInput == 1):
        timeW = 25              #set time to 25 minutes
        timeW *= 60             #times by 60 to make it minutes
        try:
            while timeW >= 0:
                min, sec = divmod(timeW, 60)
                countdown = (str(min).zfill(2) + ":" + str(sec).zfill(2))
                print (countdown + "\r", end = "")
                time.sleep(1)
                timeW -= 1

        except KeyboardInterrupt:
            pass

    elif (userInput == 2):
        pass


    elif (userInput == 0):
        exit()
