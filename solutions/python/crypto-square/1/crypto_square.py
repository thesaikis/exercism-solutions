from math import ceil, floor, sqrt


def cipher_text(plain_text):
    clean_text = "".join(s.lower() for s in plain_text if s.isalnum())

    c = ceil(sqrt(len(clean_text)))
    r = floor(sqrt(len(clean_text)))
    if r * c < len(clean_text):
        r = c

    return "".join(
        (clean_text[j] if j < len(clean_text) else " ")
        + (" " if i < c - 1 and j + c >= r * c else "")
        for i in range(c)
        for j in range(i, r * c, c)
    )
