def only_ints(a, b):
    return str(type(a)) == '<class \'int\'>' and str(type(b)) == '<class \'int\'>'


print(only_ints("a", 1))
print(only_ints(11, 1))
