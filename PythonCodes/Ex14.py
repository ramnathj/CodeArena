'''
Count of upper case and lower case letters
in a sentence
'''


class CountCase(object):

    def __init__(self,s):
        self.s=s

    def countLower(self):
        return len(filter(lambda x : x >= 'a' and x <= 'z', self.s[:]))

    def countUpper(self):
        return len(filter(lambda x : x >= 'A' and x <= 'Z', self.s[:]))


s = raw_input("Enter the sentence : ")
C = CountCase(s)
print 'UPPER CASE ', C.countUpper()
print 'LOWER CASE ', C.countLower()

