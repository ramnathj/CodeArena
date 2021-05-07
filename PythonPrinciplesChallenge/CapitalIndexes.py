def capital_indexes(st):
    return [i for i in range(len(st)) if st[i].isupper()]


st = input()
idx_list = capital_indexes(st)
print(idx_list)
