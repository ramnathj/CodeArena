def zap(lst1, lst2):
    return [(lst1[i], lst2[i]) for i in range(len(lst1))]


print(zap([0, 1, 2, 3], [5, 6, 7, 8]))
