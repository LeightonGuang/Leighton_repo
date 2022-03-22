deck = []

class Card(object):
    def __init__(self, suit, val):
        self.suit = suit
        self.value = val

    def show(self):
        print ("{} of {}".format(self.value, self.suit))

class Deck(object):
    def __init__(self):
        pass


class Player(object):
    def __init__():
        self.name = name
        self.chip = chip
        self.hand = hand

class Dealer(object):
    def __init__():
        self

card = Card("clubs", 6)
card.show()
