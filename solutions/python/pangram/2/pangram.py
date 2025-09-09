def is_pangram(sentence):
    return set(sentence.lower()) >= set(chr(c) for c in range(ord("a"), ord("z") + 1))
