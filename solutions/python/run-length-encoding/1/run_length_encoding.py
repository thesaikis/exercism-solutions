from itertools import groupby
from re import findall


def decode(string):
    return "".join(
        char * (int(num) if num else 1) for num, char in findall(r"(\d+)?(\D)", string)
    )


def encode(string):
    return "".join(
        f"{count if count > 1 else ''}{char}"
        for char, count in ((c, len(list(g))) for c, g in groupby(string))
    )
