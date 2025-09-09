def rail_cipher(input, rails, do_encode):
    max_gap = 2 * rails - 2
    out_idx = 0
    out = [0] * len(input)

    for i in range(rails):
        idx = i
        gap = max_gap - 2 * i

        if i == rails - 1:
            gap = max_gap

        while idx < len(input):
            if do_encode:
                out[out_idx] = input[idx]
            else:
                out[idx] = input[out_idx]

            idx += gap
            out_idx += 1

            if i != 0 and i != rails - 1:
                gap = max_gap - gap

    return "".join(out)


def encode(message, rails):
    return rail_cipher(message, rails, True)


def decode(encoded_message, rails):
    return rail_cipher(encoded_message, rails, False)
