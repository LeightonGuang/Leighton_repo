word = "leighton"
underline = []
guess = ""
counter = 0

for i in word:
    underline.append("_")

print(underline)


def guessLetter():
    while(True):
        global guess
        guess = input("\nplease enter an letter: ")
        print("length: ", len(guess))

        if(len(guess) == 1):
            return guess


def showLetter():
    for i in underline:
        print(i, end=" ")


def replace():
    for i in range(len(word)):
        if(guess == word[i]):
            underline[i] = guess

        elif(i == len(word)):
            counter += 1


def checkWord():
    for i in range(len(word)):
        if(word[i] == underline[i] and i == (len(word) - 1)):
            print("\nYou Win!")
            exit()

        elif(word[i]) != underline[i]:
            #print("still missing letters")
            break


while(counter < 9):
    guessLetter()
    replace()
    showLetter()
    checkWord()
