def spiral_matrix(size):
    mat = [[0] * size for _ in range(size)]
    x, y = 0, 0
    dx, dy = 1, 0

    for n in range(1, size ** 2 + 1):
        mat[y][x] = n

        if x + dx < 0 or x + dx >= size or y + dy < 0 or y + dy >= size or mat[y + dy][x + dx] != 0:
            dx, dy = -dy, dx
        
        x, y = x + dx, y + dy

    return mat