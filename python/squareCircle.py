import math
import random


def sqr(num):
    return num * num


missTimes = 0
hitTimes = 0
diameter = 10
squareArea = sqr(diameter)
circleArea = (math.pi) * sqr(diameter/2)
chance = circleArea / squareArea


loop = 0
while (loop != "1"):
    hit = random.random()
    if (hit <= chance):
        hitTimes += 1
        print("(hit)")
        print("hit: ", hitTimes, "miss: ", missTimes,
              "total: ", missTimes + hitTimes)
        print((missTimes / (missTimes + hitTimes)) * 10)

    else:
        missTimes += 1
        print("(miss)")
        print("hit: ", hitTimes, "miss: ", missTimes,
              "total: ", missTimes + hitTimes)
        print((missTimes / (missTimes + hitTimes)) * 10)

    loop = input("1 to end>")

# print(chance)
# print(hit)
