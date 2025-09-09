from string import ascii_lowercase
from random import choice


class Cipher:
    _RANDOM_KEY_LEN = 100

    def __init__(self, key=None):
        self.key = (
            "".join(choice(ascii_lowercase) for _ in range(Cipher._RANDOM_KEY_LEN))
            if key is None
            else key
        )

    def encode(self, text):
        return self.generic_cipher(lambda x, y: x + y, text)

    def decode(self, text):
        return self.generic_cipher(lambda x, y: x - y, text)

    def generic_cipher(self, op, text):
        return "".join(
            chr((
                op(ord(c), ord(self.key[key_idx % len(self.key)]) - ord("a"))
                - ord("a"))
                % 26 + ord("a")
            )
            for key_idx, c in enumerate(text)
        )
