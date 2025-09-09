def response(hey_bob):
    """
    Bob's response to the phrase said to him.

    Args:
        hey_bob (string): The phrase said to bob.

    Returns:
        string: Bob's reply.
    """
    if hey_bob.isspace() or hey_bob == "":
        return "Fine. Be that way!"
    if hey_bob.isupper() and hey_bob.rstrip()[-1] == "?":
        return "Calm down, I know what I'm doing!"
    if hey_bob.isupper():
        return "Whoa, chill out!"
    if hey_bob.rstrip()[-1] == "?":
        return "Sure."
    return "Whatever."
