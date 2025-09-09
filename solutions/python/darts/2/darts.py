def score(x, y):
    match x * x + y * y:
        case n if -1 <= n <= 1: return 10
        case n if -25 <= n <= 25: return 5
        case n if -100 <= n <= 100: return 1
        case _: return 0
