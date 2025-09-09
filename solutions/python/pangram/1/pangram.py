def is_pangram(sentence):
    return set(range(ord('a'), ord('z')+1)) == set(ord(c) for c in sentence.lower() if c.isalpha())
