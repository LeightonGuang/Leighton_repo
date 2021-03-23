import time

while True:
    userInput = int(input("""
________________________________________
|           [Pomodor Timer]            |
|   [1] 25 mins work and 5 mins break  |
|   [2] 50 mins work and 10 mins break |
|   [0] to quit                        |
|______________________________________|

>> """))

    #print ("\n")
    if (userInput == 1):
        timeW = 25              #set work time to 25 minutes
        timeW *= 60             #times by 60 to make it minutes

        timeB = 5               #set break time to 5 minutes
        timeB *= 60             #times by 60 to make it minutes
        try:
            while timeW >= 0:
                min, sec = divmod(timeW, 60)
                countdown = ("[" + str(min).zfill(2) + ":" + str(sec).zfill(2) + "]")
                print (countdown + "\r", end = "")
                time.sleep(1)
                timeW -= 1

            print ("[BREAK TIME]")
            userInput = input("press [enter] to start Break")

            while timeB >= 0:
                min, sec = divmod(timeB, 60)
                countdown = ("[" + str(min).zfill(2) + ":" + str(sec).zfill(2) + "]")
                print (countdown + "\r", end = "")
                time.sleep(1)
                timeB -= 1

        except KeyboardInterrupt:
            pass

    elif (userInput == 2):
        timeW = 50              #set work time to 25 minutes
        timeW *= 60             #times by 60 to make it minutes

        timeB = 10               #set break time to 10 minutes
        timeB *= 60             #times by 60 to make it minutes
        try:
            while timeW >= 0:
                min, sec = divmod(timeW, 60)
                countdown = ("[" + str(min).zfill(2) + ":" + str(sec).zfill(2) + "]")
                print (countdown + "\r", end = "")
                time.sleep(1)
                timeW -= 1

            print ("[BREAK TIME]")
            userInput = input("press [enter] to start Break")

            while timeB >= 0:
                min, sec = divmod(timeB, 60)
                countdown = ("[" + str(min).zfill(2) + ":" + str(sec).zfill(2) + "]")
                print (countdown + "\r", end = "")
                time.sleep(1)
                timeB -= 1

        except:
            pass

    elif (userInput == 0):
        print ("Quit")
        exit()
