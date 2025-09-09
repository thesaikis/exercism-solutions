def primes(limit):
    is_prime = [True] * (limit - 1)

    for i in range(2, limit + 1):
        if not is_prime[i - 2]:
            continue
        
        for n in range(i, limit + 1, i):
            if n == i:
                continue
            is_prime[n - 2] = False

    return list(p for p in range(2, limit + 1) if is_prime[p - 2])
