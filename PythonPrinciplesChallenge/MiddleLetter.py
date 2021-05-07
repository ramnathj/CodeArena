def mid(st):
    n = len(st)
    return st[int(n / 2)] if n % 2 != 0 else ''


print(mid("abc"))
print(mid("aaaa"))
