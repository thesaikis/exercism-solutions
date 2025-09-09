from math import sqrt, floor


def prime(number):
    if number == 0:
        raise ValueError("there is no zeroth prime")
    if number == 1:
        return 2

    found = 1
    prime = 3

    while found < number:
        is_prime = True
        for i in range(2, floor(sqrt(prime)) + 1):
            if prime % i == 0:
                is_prime = False
                break

        if is_prime:
            found += 1

        if found < number:
            prime += 2

    return prime
