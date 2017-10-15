'''
2-D Array
'''


class Matrix(object):

    def __init__(self,x,y):
        self.x = x
        self.y = y
        self.mat = []

    def compute(self):
        for i in xrange(self.x):
            lst=[]
            for j in xrange(self.y):
                lst.append(i*j)
            self.mat.append(lst)
        return self.mat


X = input('Enter the number of rows : ')
Y = input('Enter the number of columns : ')
M = Matrix(X,Y)
print M.compute()

