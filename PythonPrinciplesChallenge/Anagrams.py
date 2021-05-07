def is_anagram(s1, s2):
    l1 = list(s1)
    l2 = list(s2)
    l1.sort()
    l2.sort()
    s1 = ''.join(l1)
    s2 = ''.join(l2)
    return s1 == s2


print(is_anagram("typhoon", "opython"))
