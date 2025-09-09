def rotate(text, key):
    def rotate_char(char):
        if char.isalpha():
            offset = ord("a") if char.islower() else ord("A")
            return chr((ord(char) - offset + key) % 26 + offset)
        else:
            return char

    return "".join(map(rotate_char, text))
