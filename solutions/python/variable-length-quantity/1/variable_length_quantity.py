from math import log2


def encode(numbers):
    nums = []
    mask = 0x7F

    for n in numbers:
        if n == 0:
            nums.append(0)
            continue

        mask_offset = int(log2(n)) // 7

        while mask_offset >= 0:
            nums.append(
                (n & mask << (mask_offset * 7)) >> (mask_offset * 7)
                | (0x80 if mask_offset > 0 else 0)
            )
            mask_offset -= 1

    return nums


def decode(bytes_):
    nums = []

    to_add, incomplete = 0, False

    for n in bytes_:
        if n >> 7 != 1:
            nums.append(to_add | n)
            to_add, incomplete = 0, False
        else:
            to_add, incomplete = (to_add | (n & 0x7F)) << 7, True

    if incomplete:
        raise ValueError("incomplete sequence")

    return nums
