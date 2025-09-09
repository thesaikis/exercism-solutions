def is_paired(input_string: str) -> bool:
    stack = []

    for c in input_string:
        if c in "{[(":
            stack.append(c)
        elif c in "}])":
            if len(stack) == 0:
                return False
            popped = stack.pop()
            if ord(popped) + 2 != ord(c) and ord(popped) + 1 != ord(c):
                return False

    return len(stack) == 0
