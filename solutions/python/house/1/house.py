OBJS = [
    "malt",
    "rat",
    "cat",
    "dog",
    "cow with the crumpled horn",
    "maiden all forlorn",
    "man all tattered and torn",
    "priest all shaven and shorn",
    "rooster that crowed in the morn",
    "farmer sowing his corn",
    "horse and the hound and the horn",
]

ACTIONS = [
    "ate",
    "killed",
    "worried",
    "tossed",
    "milked",
    "kissed",
    "married",
    "woke",
    "kept",
    "belonged to",
]


def verse(num):
    if num == 1:
        return "This is the house that Jack built."

    phrase = [f"This is the {OBJS[num - 2]}"]
    phrase.extend(f"that {ACTIONS[i - 3]} the {OBJS[i - 3]}" for i in range(num, 2, -1))
    phrase.append("that lay in the house that Jack built.")

    return " ".join(phrase)


def recite(start_verse, end_verse):
    return [verse(i) for i in range(start_verse, end_verse + 1)]
