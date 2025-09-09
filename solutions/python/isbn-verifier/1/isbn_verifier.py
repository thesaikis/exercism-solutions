def is_valid(isbn):
    """
    Checks the validity of an ISBN-10 number.

    Args:
        isbn (str): The ISBN-10 number to be validated.

    Returns:
        bool: True if `isbn` is a valid ISBN-10, False otherwise.
    """
    new_isbn = "".join(c for c in isbn if c.isdigit() or c == "X")

    if len(new_isbn) != 10 or any(c not in "0123456789X-" for c in isbn):
        return False

    return (
        sum(10 if c == "X" else int(c) * i for c, i in zip(new_isbn, range(10, 0, -1)))
        % 11
        == 0
    )
