_flattened_nums = {
    " _ | ||_|   ": "0",
    "     |  |   ": "1",
    " _  _||_    ": "2",
    " _  _| _|   ": "3",
    "   |_|  |   ": "4",
    " _ |_  _|   ": "5",
    " _ |_ |_|   ": "6",
    " _   |  |   ": "7",
    " _ |_||_|   ": "8",
    " _ |_| _|   ": "9",
}


def chunked(m, size):
    for i in range(0, len(m[0]), size):
        yield "".join(row[i : i + size] for row in m)


def convert(input_grid):
    if len(input_grid) % 4 != 0:
        raise ValueError("Number of input lines is not a multiple of four")
    if any(len(row) % 3 != 0 for row in input_grid):
        raise ValueError("Number of input columns is not a multiple of three")

    return ",".join(
        "".join(
            _flattened_nums.get(chunk, "?")
            for chunk in chunked(input_grid[i : i + 4], 3)
        )
        for i in range(0, len(input_grid), 4)
    )
