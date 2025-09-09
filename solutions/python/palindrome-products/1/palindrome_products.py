def is_palindrome(n):
    if n < 0:
        return False

    reverse = 0
    temp = n

    while temp > 0:
        reverse = (reverse * 10) + (temp % 10)
        temp = temp // 10

    return n == reverse


def find_palindrome(min_factor, max_factor, init_value, comparison):
    if min_factor > max_factor:
        raise ValueError("min must be <= max")

    palindrome, products = init_value, []

    for a in range(max_factor, min_factor - 1, -1):
        for b in range(a, min_factor - 1, -1):
            candidate = a * b
            if comparison(candidate, palindrome):
                break
            if is_palindrome(candidate):
                if candidate != palindrome:
                    palindrome = candidate
                    products = [[a, b]]
                else:
                    products.append([a, b])

    return (palindrome, products) if palindrome != init_value else (None, [])


def largest(min_factor, max_factor):
    """Given a range of numbers, find the largest palindromes which
    are products of two numbers within that range.
    """

    return find_palindrome(min_factor, max_factor, float("-inf"), lambda x, y: x < y)


def smallest(min_factor, max_factor):
    """Given a range of numbers, find the smallest palindromes which
    are products of two numbers within that range.
    """

    return find_palindrome(min_factor, max_factor, float("inf"), lambda x, y: x > y)
