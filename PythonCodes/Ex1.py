
class Ex1(object):
    def __init__(self, lowerBound, upperBound):
        self.lower = lowerBound
        self.upper = upperBound
        self.lst = []

    def compute(self):
        for i in range(self.lower,self.upper+1):
            if i % 7 == 0 and i % 5 != 0 :
                self.lst.append(i)

    def printList(self):
        for i in range(0,len(self.lst)-1):
            print self.lst[i],",",
        print self.lst[len(self.lst)-1]

    def printList2(self):
        print ",".join(map(str,self.lst))


lower = input("Enter the lower bound : ")
upper = input("Enter the upper bound : ")
E1 = Ex1(lower,upper)
E1.compute()
E1.printList()
E1.printList2()