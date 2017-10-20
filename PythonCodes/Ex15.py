'''
Compute value of the expression a + aa + aaa + aaaa
'''


class Expr(object):
    def __init__(self,num):
        self.num = num

    def compute(self):
        sumVal = 0
        val = self.num
        for i in range(1,5):
            sumVal += val
            val = val * 10 + self.num

        return sumVal


num = input('Enter the number : ')
E = Expr(num)
print E.compute()

