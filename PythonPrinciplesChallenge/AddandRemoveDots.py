def add_dots(st):
    return '.'.join(list(st))


def remove_dots(st):
    return st.replace('.','')


print(add_dots("test"))
print(remove_dots("t.e.s.t"))