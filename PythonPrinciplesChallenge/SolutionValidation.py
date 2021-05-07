def validate(code):
    if code.find("def") == -1:
        return "missing def"
    elif code.find(":") == -1:
        return "missing :"
    elif code.find("(") == -1 or code.find(")") == -1:
        return "missing paren"
    elif code.find("()") != -1 and code.find("\"()\"") == -1:
        return "missing param"
    elif code.find("    ") == -1:
        return "missing indent"
    elif code.find("validate") == -1:
        return "wrong name"
    elif code.find("return") == -1:
        return "missing return"
    else:
        return True


print(validate("""
def validate(code):
    if code.find("def") == -1:
        return "missing def"
    elif code.find(":") == -1:
        return "missing :"
    elif code.find("(") == -1 or code.find(")") == -1:
        return "missing paren"
    elif code.find("()") != -1 and code.find("\"()\"") == -1:
        return "missing param"
    elif code.find("    ") == -1:
        return "missing indent"
    elif code.find("validate") == -1:
        return "wrong name"
    elif code.find("return") == -1:
        return "missing return"
    else:
        return True
"""))
