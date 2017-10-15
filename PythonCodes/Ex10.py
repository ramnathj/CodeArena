'''
Set Data Structure
'''


class RemoveDuplicates(object):

    def __init__(self,s):
        self.s = s

    def convert(self):
        return ' '.join(sorted(list(set(self.s.split(' ')))))


s = raw_input()
R = RemoveDuplicates(s)
print R.convert()
