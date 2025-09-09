def classify(number):
    """A perfect number equals the sum of its positive divisors.

    :param number: int a positive integer
    :return: str the classification of the input integer
    """
    if number < 1:
        raise ValueError("Classification is only possible for positive integers.")
    match sum(num for num in range(1, number // 2 + 1) if number % num == 0):
        case s if s == number: return "perfect"
        case s if s > number:  return "abundant"
        case _:                return "deficient"
