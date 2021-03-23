import time

numbers = ["one", "two", "three", "four", "five", "six"]

for i in (numbers):
    print (i + "\r", end = "")
    time.sleep(1)
