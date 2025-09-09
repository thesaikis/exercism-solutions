from itertools import combinations as combs


def combinations(target, size, exclude):
    return [list(comb) for comb in combs((n for n in range(1, 10) if n not in exclude), size) if sum(comb) == target]
