def rows(letter):
    result = []

    for c in range(ord("A"), ord(letter) + 1):
        line_to_add = (
            " " * (ord(letter) - c)
            + chr(c)
            + " " * (2 * (c - ord("A")) - 1)
            + (chr(c) if c != ord("A") else "")
            + " " * (ord(letter) - c)
        )

        if c < ord(letter):
            result.insert(c - ord("A"), line_to_add)
        result.insert(c - ord("A"), line_to_add)

    return result
