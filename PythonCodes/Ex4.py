'''
Generate list and tuple
'''
class Generate(object):
    def __init__(self,s):
        self.s=s

    def generateList(self):
        print self.s.split(',')

    def generateTuple(self):
        print tuple(self.s.split(','))


s=raw_input("Enter the comma separated sequence : ")
G = Generate(s)
G.generateList()
G.generateTuple()

