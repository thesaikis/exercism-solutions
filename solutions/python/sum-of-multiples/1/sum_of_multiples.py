def sum_of_multiples(limit, multiples):
    return sum(set(n for mult in multiples if mult != 0 for n in range(mult, limit, mult)))
