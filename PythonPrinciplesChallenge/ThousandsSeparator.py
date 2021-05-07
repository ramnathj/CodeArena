def format_number(n):
    st = list(str(n))
    st.reverse()
    l = len(st)
    next_pos = 3
    while l > next_pos:
        st.insert(next_pos, ",")
        l = len(st)
        next_pos += 4
    st.reverse()
    return "".join(st)


print(format_number(100000))
print(format_number(100000000))
print(format_number(1000000))
print(format_number(100))
print(format_number(1000))
print(format_number(10))
print(format_number(1))
