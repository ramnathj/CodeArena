'''
Convert String to UpperCase
'''


class String(object):
    def __init__(self):
        self.s=""

    def getString(self):
        self.s=raw_input()

    def printString(self):
        print self.s.upper()


S = String()
S.getString()
S.printString()