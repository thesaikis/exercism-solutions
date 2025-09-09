REVERSE_ALPHA = "zyxwvutsrqponmlkjihgfedcba"


def generic_atbash(text, do_space=True):
    count = 0
    for let in text:
        if let.isalpha() or let.isdigit():
            if do_space and count and count % 5 == 0:
                yield " "
            yield REVERSE_ALPHA[ord(let.lower()) - ord("a")] if let.isalpha() else let
            count += 1


def encode(plain_text):
    return "".join(generic_atbash(plain_text))


def decode(ciphered_text):
    return "".join(generic_atbash(ciphered_text, do_space=False))
