def leap_year(year):
    """
    Check if a given year is a leap year.

    Args:
        year (int): The year to be checked

    Returns:
        bool: True if the year is a leap year. False otherwise.
    """
    return year % 400 == 0 or year % 4 == 0 and year % 100 != 0
