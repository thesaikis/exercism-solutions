def egg_count(display_value):
    """
    Count the number of 1's in a binary representation of a number.

    Args:
        display_value (int): The value to count the 1's from.

    Returns:
        int: The number of 1's in the binary representation of `display_value`.
    """
    return bin(display_value).count("1")
