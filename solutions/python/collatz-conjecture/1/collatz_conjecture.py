def steps(number):
    """
    Calculates the number of steps needed to reach 1 via the Collatz Conjecture.

    Args:
        number (int): The positive integer to calculate steps for.

    Raises:
        ValueError: When `number` is less than 1.

    Returns:
        int: The number of steps to reach one.
    """
    if number < 1:
        raise ValueError("Only positive integers are allowed")

    steps = 0
    while number != 1:
        number = number / 2 if number % 2 == 0 else 3 * number + 1
        steps += 1
    return steps
