'''
Function Computation
'''

import math


class Quant(object):
    def __init__(self,d,**kwargs):
        self.D = d
        self.C = kwargs['C']
        self.H = kwargs['H']

    def compute(self):
        return str(int(math.sqrt(2 * self.C * self.D / self.H )))


s = raw_input("Enter the input sequence : ")
lst = []
for elem in map(int,s.split(',')):
    Q = Quant(elem,C=50,H=30)
    lst.append(Q.compute())

print ",".join(lst)


