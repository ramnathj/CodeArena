def consecutive_zeros(st):
    max_len = 0
    n = len(st)
    i = 0
    while i < n:
        if st[i] == '0':
            l = 0
            while i < n and st[i] == '0':
                l += 1
                i += 1
            max_len = max(max_len, l)
        else:
            i += 1
    return max_len


print(consecutive_zeros("1001101000110"))
