'''
Even Digit numbers in a Range
'''


class Even(object):
    def __init__(self,lb,ub):
        self.lb = lb
        self.ub = ub
        self.lst = []

    def compute(self):
        for elem in range(self.lb,self.ub+1):
            numLst = []
            num = elem
            flag = True
            while num > 0 :
                rem = num % 10
                if rem % 2 == 1 :
                    flag = False
                    break
                num = num / 10
            if flag:
                self.lst.append(elem)

    def printLst(self):
        return ','.join(map(str,self.lst))


lb = input('Enter lower bound : ')
ub = input('Enter upper bound : ')
E = Even(lb, ub)
E.compute()
print E.printLst()
