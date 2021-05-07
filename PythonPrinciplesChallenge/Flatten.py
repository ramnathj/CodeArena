def flatten(lst):
    final_lst = []
    for k in lst:
        final_lst.extend(k)
    return final_lst


print(flatten([[1, 2], [3, 4]]))
