MAX_SAY = 999999999999
MIN_SAY = 0

PLACES = ["billion", "million", "thousand"]
TENS = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
ONE_N_TEENS = [
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
]


def say(number):
    if not (MIN_SAY <= number <= MAX_SAY):
        raise ValueError("input out of range")
    if number == 0:
        return "zero"

    divisor = 1000000000
    places_idx = 0
    says = []

    while number >= 1:
        to_say = number // divisor

        if to_say > 0:
            if to_say // 100 > 0:
                says.append(f"{ONE_N_TEENS[to_say // 100]} hundred")
                to_say %= 100

            if to_say // 10 > 1:
                ones = f"-{ONE_N_TEENS[to_say % 10]}" if to_say % 10 > 0 else ""
                says.append(f"{TENS[to_say // 10 - 2]}{ones}")
                to_say = 0
            elif to_say // 10 > 0:
                says.append(f"{ONE_N_TEENS[to_say]}")
                to_say = 0

            if to_say > 0:
                says.append(f"{ONE_N_TEENS[to_say]}")

            if places_idx < len(PLACES):
                says.append(f"{PLACES[places_idx]}")

        number %= divisor
        divisor //= 1000
        places_idx += 1

    return " ".join(says)
