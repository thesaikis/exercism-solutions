def equilateral(sides):
    """
    Check if a triangle with given side lengths is equilateral.

    Args:
        sides (list): A list of three side lengths.

    Returns:
        bool: True if the triangle is equilateral, False otherwise.
    """

    return all(side == sides[0] and side != 0 for side in sides)


def isosceles(sides):
    """
    Check if a triangle with given side lengths is isosceles.

    Args:
        sides (list): A list of three side lengths.

    Returns:
        bool: True if the triangle is isosceles, False otherwise.
    """

    return is_valid(*sides) and len(set(sides)) in [1, 2]


def scalene(sides):
    """
    Check if a triangle with given side lengths is scalene.

    Args:
        sides (list): A list of three side lengths.

    Returns:
        bool: True if the triangle is isosceles, False otherwise.
    """

    return is_valid(*sides) and len(set(sides)) == 3


def is_valid(s1, s2, s3):
    """
    Check if the given side lengths for a valid triangle.

    Args:
        s1: The first side length.
        s2: The second side length.
        s3: The third side length

    Returns:
        bool: True if the side lengths for a valid triangle, False otherwise.
    """

    return s1 + s2 >= s3 and s2 + s3 >= s1 and s1 + s3 >= s2
