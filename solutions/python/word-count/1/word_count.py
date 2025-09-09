from re import findall
from collections import defaultdict


def count_words(sentence):
    words = defaultdict(int)

    for word in findall(r"[a-zA-Z0-9]+(?:\'[a-zA-Z0-9]+)?", sentence):
        words[word.lower()] += 1

    return words
