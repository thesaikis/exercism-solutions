def square_root(number):
    x, y, prev = number, 0, -1

    while prev != y:
        prev, y = y, (x + number // x) // 2
        x = y

    return y
