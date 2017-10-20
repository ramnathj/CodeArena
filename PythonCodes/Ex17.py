'''
Transaction Output
'''


class Transaction(object):

    def __init__(self):
        self.amt = 0

    def compute(self):
        s = raw_input()
        while s :
            arr = s.split()
            amount = int(arr[1])
            if arr[0] == 'D':
                self.amt += amount
            elif arr[0] == 'W':
                self.amt -= amount
            s = raw_input()

        return self.amt


T = Transaction()
print T.compute()
