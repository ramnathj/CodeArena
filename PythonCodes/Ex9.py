'''
Capitalize Sentences and Print
'''


class Capitalize(object):

    def __init__(self,s):
        self.s=s

    def convert(self):
        return self.s.upper()


s = raw_input()
while s :
    C = Capitalize(s)
    print C.convert()
    s = raw_input()
