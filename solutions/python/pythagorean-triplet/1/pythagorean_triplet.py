def triplets_with_sum(number):
    return list(
        [a, b, c]
        for a in range(1, number // 3)
        for b in range(a + 1, (number - a) // 2 + 1)
        if a**2 + b**2 == (c := number - b - a) ** 2
    )
