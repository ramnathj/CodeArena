'''
Dictionary Of Square Numbers
'''


class SquareMap(object):
    def __init__(self,num):
        self.num=num
        self.sqDict={}

    def createDictionary(self):
        for i in xrange(1,self.num+1):
            self.sqDict[i]=i*i
        return self.sqDict


n = input('Enter the upper bound : ')
S = SquareMap(n)
print S.createDictionary()

#One liner equivalent of above code
print dict(zip(range(1,n+1),map(lambda x: x * x, range(1,n+1))))
