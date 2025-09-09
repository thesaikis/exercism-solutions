GIFTS = [
    "a Partridge in a Pear Tree.",
    "two Turtle Doves",
    "three French Hens",
    "four Calling Birds",
    "five Gold Rings",
    "six Geese-a-Laying",
    "seven Swans-a-Swimming",
    "eight Maids-a-Milking",
    "nine Ladies Dancing",
    "ten Lords-a-Leaping",
    "eleven Pipers Piping",
    "twelve Drummers Drumming",
]

DAYS = [
    "first",
    "second",
    "third",
    "fourth",
    "fifth",
    "sixth",
    "seventh",
    "eighth",
    "ninth",
    "tenth",
    "eleventh",
    "twelfth",
]


def verse(day):
    return f"On the {DAYS[day]} day of Christmas my true love gave to me: " + ", ".join(
        "and " + GIFTS[i] if day > 0 and i == 0 else GIFTS[i]
        for i in range(day, -1, -1)
    )


def recite(start_verse, end_verse):
    return [verse(day - 1) for day in range(start_verse, end_verse + 1)]
