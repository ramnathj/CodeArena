'''
Square each odd number in a list
'''

import math


class SquareOdd(object):

    def __init__(self,s):
        self.s=s

    def compute(self):
        return ','.join(map(lambda x : str(x * x), filter(lambda x : x % 2 == 1, map(int,self.s.split(',')))))


s = raw_input('Enter the numbers : ')
S = SquareOdd(s)
print S.compute()
