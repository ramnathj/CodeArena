'''
Binary Strings divisible by 5
'''


class Binary(object):
    def __init__(self,s):
        self.s = s

    def toInt(self,num):
        return

    def compute(self):
        return ','.join(filter(lambda x: int(x,2) % 5 == 0, self.s.split(',')))

s = raw_input()
B = Binary(s)
print B.compute()
