def factors(value):
    primes = []
    i = 2

    while value > 1:
        while value % i == 0:
            primes.append(i)
            value /= i
        i += 1

    return primes
