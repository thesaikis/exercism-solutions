SCORES = {
    "Q": 10,
    "Z": 10,
    "J": 8,
    "X": 8,
    "K": 5,
    "F": 4,
    "H": 4,
    "V": 4,
    "W": 4,
    "Y": 4,
    "B": 3,
    "C": 3,
    "M": 3,
    "P": 3,
    "D": 2,
    "G": 2,
}


def score(word):
    return sum(SCORES.get(c.upper(), 1) for c in word if c.isalpha())
