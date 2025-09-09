ACTIONS = ["wink", "double blink", "close your eyes", "jump"]


def commands(binary_str):
    seq = [action for idx, action in enumerate(ACTIONS) if int(binary_str, 2) & 1 << idx]
    return seq[::-1] if binary_str[0] == '1' else seq
