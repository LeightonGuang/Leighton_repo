import random
import tkinter
import time

wordList = ["been", "went", "out", "study", "want", "even", "might", "something", "eat", "ask", "white", "write", "mother", "something", "of", "three", "a", "long", "as", "follow", "food", "on", "we", "much", "song", "while", "red", "group", "play", "again", "only", "stop", "came", "carry", "great", "than", "between", "or", "away", "take", "could", "walk", "call", "young", "what", "play", "much", "which", "may", "saw", "last", "under", "are", "example", "idea", "then", "name", "black", "many", "part", "walk", "form", "or", "something", "boy", "this", "men", "miss", "light", "black", "men", "right", "almost", "that", "their", "mile", "place", "men", "soon", "water", "sun"]

wrongWords = []

rightCounter = 0
wrongCounter = 0

start = time.time()

for i in range (10):
  randNum = random.randint(0,80)
  randWord = wordList[randNum]
  print(randWord)
  userInput = input("> ")

  if (randWord == userInput):
    print("Correct")
    rightCounter += 1

  elif (randWord != userInput):
    print("Wrong")
    wrongWords.append(userInput)
    wrongCounter += 1

stop = time.time()
print("\n")
print("Words right:", rightCounter)
print("Words wrong", wrongCounter)

totalTime = stop - start
print ("Time: ", totalTime, "s")
print ("wrong words")
for i in (wrongWords):
  print (i)
#time_convert(totalTime)
