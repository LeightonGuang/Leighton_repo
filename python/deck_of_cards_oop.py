import random

#print ('Deck of cards')

class Cards:
    def __init__(self, suit, val):
        self.suit = suit
        self.val = val

    def show(self):
        print ('{} of {}'.format(self.val, self.suit))

class Deck:
    def __init__(self):
        self.cards = []             #card list
        self.build()
        pass

    def build(self):
        for s in ['Spades', 'Clubs', 'Diamonds', 'Hearts']:     # s = suite

            for v in range (1, 14):         #v = values     changes 1, 11 , 12, 13 to A, J, Q, K
                if (v == 1):
                    v = 'A'

                elif (v == 11):
                    v = 'J'

                elif (v == 12):
                    v = 'Q'

                elif (v == 13):
                    v = 'K'

                #print ('{} of {}').format(v, s)     # prints out all 52 cards
                self.cards.append(Cards(s, v))      # add the build deck card to card list in deck class

    def show(self):
        for c in self.cards:                # for every cards in self.cards list in class deck
            c.show()                        # show that card

    def shuffle(self):
        for i in range (len(self.cards) -1, 0, -1):
            r = random.randint(0, i)
            self.cards[i], self.cards[r] = self.cards[r], self.cards[i]

    def drawCard(self):
        return self.cards.pop()

class Player:
    def __init__(self, name):
        self.name = name
        self.hand = []

    def draw(self, deck):
        self.hand.append(deck.drawCard())
        return self

    def showHand(self):
        for card in self.hand:
            card.show()

#card = Cards('Clubs', 6)
#card.show()

deck = Deck()
deck.shuffle()
#deck.show()

leighton = Player('Leighton')
leighton.draw(deck)
leighton.showHand()
print (leighton.name)           #prints name Leighton

# card = deck.draw()
# card.show()
