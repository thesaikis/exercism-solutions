from math import log


def rebase(input_base, digits, output_base):
    if input_base < 2:
        raise ValueError("input base must be >= 2")
    if output_base < 2:
        raise ValueError("output base must be >= 2")
    if any(not (0 <= d < input_base) for d in digits):
        raise ValueError("all digits must satisfy 0 <= d < input base")

    base_10 = sum(n * (input_base**b) for n, b in zip(reversed(digits), range(len(digits))))

    if base_10 == 0:
        return [0]

    ans = []

    for exp in range(int(log(base_10) / log(output_base)), -1, -1):
        ans.append(base_10 // (output_base**exp))
        base_10 %= output_base**exp

    return ans
