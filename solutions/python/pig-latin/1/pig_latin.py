import re


pat = re.compile(r"(x(?!r)|y(?!t)|[^aeiouqxy]*(qu?)?)(\w+)")


def translate(text):
    return " ".join(
        map(
            lambda word: pat.sub(
                lambda match: f"{match.groups()[2]}{match.groups()[0]}ay", word
            ),
            text.split(),
        )
    )
