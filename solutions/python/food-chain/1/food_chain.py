animals = [
    ("fly", ""),
    ("spider", "fly"),
    ("bird", "spider that wriggled and jiggled and tickled inside her"),
    ("cat", "bird"),
    ("dog", "cat"),
    ("goat", "dog"),
    ("cow", "goat"),
]

jokes = [
    "",
    "It wriggled and jiggled and tickled inside her.",
    "How absurd to swallow a bird!",
    "Imagine that, to swallow a cat!",
    "What a hog, to swallow a dog!",
    "Just opened her throat and swallowed a goat!",
    "I don't know how she swallowed a cow!",
]


def verse(num):
    if num == 7:
        return ["I know an old lady who swallowed a horse.", "She's dead, of course!"]

    res = [f"I know an old lady who swallowed a {animals[num][0]}."]
    if num > 0:
        res.append(jokes[num])

    for v in range(num, 0, -1):
        swallowed, to_catch = animals[v]
        res.append(f"She swallowed the {swallowed} to catch the {to_catch}.")

    res.append("I don't know why she swallowed the fly. Perhaps she'll die.")

    return res


def recite(start_verse, end_verse):
    verses = []

    for v in range(start_verse - 1, end_verse):
        verses.extend(verse(v))
        if v != end_verse - 1:
            verses.append("")

    return verses
