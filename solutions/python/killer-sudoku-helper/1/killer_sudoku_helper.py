from itertools import combinations as combs


def combinations(target, size, exclude):
    # ans = []
    # gen = (i for i in range(1, 10) if i not in exclude)

    # for comb in combs(gen, size):
    #     if sum(comb) == target:
    #         ans.append(list(comb))

    # return ans

    return [list(comb) for comb in combs((n for n in range(1, 10) if n not in exclude), size) if sum(comb) == target]
