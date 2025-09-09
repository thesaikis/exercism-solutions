def square(number):
    """
    Calculate the number of grains on a square of a chessboard.

    Args:
        number (int): The number of the square (1 to 64).

    Raises:
        ValueError: If `number` is not between 1 and 64.

    Returns:
        int: The number of grains on the specified square.
    """
    if number < 1 or number > 64:
        raise ValueError("square must be between 1 and 64")
    return 2 ** (number - 1)


def total():
    """
    Calculate the total number of grains on the entire chessboard.

    Returns:
        int: The number of grains on the entire chessboard.
    """
    return sum(square(i) for i in range(1, 65))
