'''
Program to compute Factorial of a number
using recursion
'''


class Factorial(object):
    def __init__(self,num):
        self.num=num

    def compute(self):
        return reduce(lambda x, y: x * y, range(1, self.num+1))


num = input("Enter the number : ")
F = Factorial(num)
print F.compute()
