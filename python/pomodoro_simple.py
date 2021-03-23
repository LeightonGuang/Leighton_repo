import time

while True:
    userInput = int(input("""
                [Pomodor Timer]
[1] to start
[2] to stop
[0] to exit
>> """))

    if (userInput == 1):
        timeW = 25
        timeW *= 60
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
