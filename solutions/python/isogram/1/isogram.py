def is_isogram(string):
    return len(set(string.lower()) - set("- ")) == len(string.lower().replace("-", "").replace(" ", ""))
