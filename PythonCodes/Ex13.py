'''
Count Letters and Digits
'''


class CountChar(object):

    def __init__(self,s):
        self.s = s
        self.digitCount = 0
        self.letterCount = 0

    def isDigit(self,c):
        return c >= '0' and c <= '9'

    def isAlphabet(self,c):
        return (c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z')

    def compute(self):
        self.digitCount = len(filter(lambda x : self.isDigit(x), list(self.s)))
        self.letterCount = len(filter(lambda x : self.isAlphabet(x), list(self.s)))

    def printCounts(self):
        print "Letters ", self.letterCount
        print "Digits ", self.digitCount


s = raw_input()
C = CountChar(s)
C.compute()
C.printCounts()
