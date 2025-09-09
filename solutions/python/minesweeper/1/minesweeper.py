POS = [(1, 0), (0, 1), (-1, 0), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]
VALID = "* "


def count(x, y, field):
    if field[y][x] not in VALID:
        raise ValueError("The board is invalid with current input.")
    if not field[y][x] == " ":
        return field[y][x]

    count = 0

    for dx, dy in POS:
        if not (
            y + dy < 0 or y + dy >= len(field) or x + dx < 0 or x + dx >= len(field[y])
        ):
            print(x + dx, y + dy)
            if field[y + dy][x + dx] == "*":
                count += 1

    return str(count) if count > 0 else " "


def annotate(minefield):
    if minefield and any(
        len(minefield[i]) != len(minefield[0]) for i in range(0, len(minefield))
    ):
        raise ValueError("The board is invalid with current input.")

    return [
        "".join(count(x, y, minefield) for x in range(len(line)))
        for y, line in enumerate(minefield)
    ]
