from itertools import zip_longest


def transpose(lines):
    new_lines = lines.split("\n")

    for i in range(len(new_lines) - 2, -1, -1):
        if len(new_lines[i + 1]) > len(new_lines[i]):
            new_lines[i] = new_lines[i].ljust(len(new_lines[i + 1]))

    return "\n".join("".join(line) for line in zip_longest(*new_lines, fillvalue=""))
