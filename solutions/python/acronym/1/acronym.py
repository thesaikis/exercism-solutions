def abbreviate(words):
    return ''.join(c.upper() for i, c in enumerate(words) if i == 0 or words[i-1] in " -_" and c.isalpha())
