def strike():
    pass

def spare():
    pass

def openFrame():
    pass

Game = True
total = 0

#while Game == True:
for frame in range (1,11):
    Frames = frame
    print("Score for frame", frame)
    #score = int(input("Score for Frame", Frames))
    score = int(input())
    total += score

print("total = ", total)
