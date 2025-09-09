def answer(question):
    question = (
        question.replace("What is", "")
        .replace("plus", "+")
        .replace("minus", "-")
        .replace("divided by", "/")
        .replace("multiplied by", "*")
        .replace("?", "")
        .strip()
    )

    # Checks if question == "", which is when the original was "What is?"
    if not question:
        raise ValueError("syntax error")

    # Check if the question has been reduced to just a number.
    if question.isdigit():
        return int(question)

    # Check if any of the operators appear in the question.
    if all(c not in question for c in "+-/*"):
        raise ValueError("unknown operation")

    question = question.split()
    while len(question) > 1:
        try:
            total, op, num, *rest = question

            if op not in "+-/*":
                raise ValueError

            question = [eval(f"{total}{op}{num}"), *rest]
        except (ValueError, SyntaxError):
            raise ValueError("syntax error")

    return question[0]
