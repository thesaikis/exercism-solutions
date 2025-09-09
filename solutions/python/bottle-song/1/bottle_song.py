LYRICS = [
    "{} green bottle{} hanging on the wall,",
    "And if one green bottle should accidentally fall,",
    "There'll be {} green bottle{} hanging on the wall.",
]

NUMS = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"]


def recite(start, take=1):
    return [
        item
        for n in range(start, start - take, -1)
        for item in [
            LYRICS[0].format(NUMS[n - 1].capitalize(), "" if n == 1 else "s"),
            LYRICS[0].format(NUMS[n - 1].capitalize(), "" if n == 1 else "s"),
            LYRICS[1],
            LYRICS[2].format("no" if n < 2 else NUMS[n - 2], "" if n == 2 else "s"),
            "" if n > start - take + 1 else None,
        ]
        if item is not None
    ]
