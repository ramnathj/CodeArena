'''
Sort strings in lexicographic order
'''


class Sorting(object):

    def __init__(self,lst):
        self.lst=lst

    def sortStrings(self):
        self.lst = sorted(self.lst)

    def printStrings(self):
        print ','.join(self.lst)


s = raw_input()
S = Sorting(s.split(','))
S.sortStrings()
S.printStrings()
