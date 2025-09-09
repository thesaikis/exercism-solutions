def leap_year(year):
    """
    Check if a given year is a leap year.

    Args:
        year (int): The year to be checked

    Returns:
        bool: True if the year is a leap year. False otherwise.
    """
    return not (year % 400) or not (year % 4) and year % 100 != 0
