def is_armstrong_number(number):
    """
    Calculate if a number is an Armstrong number.

    An armstrong number is a number that is the sum of its own digits
    raised to the power of the number of digits.

    Args:
        number (int): The number to check if its an Armstrong number.

    Returns:
        bool: True if `number` is an Armstrong number, otherwise False.
    """

    return sum(int(num) ** len(str(number)) for num in str(number)) == number
