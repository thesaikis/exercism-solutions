TOLERANCES = {
    "grey": "0.05%",
    "violet": "0.1%",
    "blue": "0.25%",
    "green": "0.5%",
    "brown": "1%",
    "red": "2%",
    "gold": "5%",
    "silver": "10%",
}

COLORS = [
    "black",
    "brown",
    "red",
    "orange",
    "yellow",
    "green",
    "blue",
    "violet",
    "grey",
    "white",
]


def resistor_label(colors):
    resistance = 0

    match colors:
        case ["black"]:
            return "0 ohms"
        case [v1, v2, mult, _]:
            resistance = (COLORS.index(v1) * 10 + COLORS.index(v2)) * (
                10 ** COLORS.index(mult)
            )
        case [v1, v2, v3, mult, _]:
            resistance = (
                COLORS.index(v1) * 100 + COLORS.index(v2) * 10 + COLORS.index(v3)
            ) * (10 ** COLORS.index(mult))

    res = f"{resistance} ohms"
    if resistance > 10**9:
        res = f"{resistance/10**9} gigaohms"
    elif resistance > 10**6:
        res = f"{resistance/10**6} megaohms"
    elif resistance > 10**3:
        res = f"{resistance/10**3} kiloohms"

    return res.replace(".0 ", " ") + f" ±{TOLERANCES[colors[-1]]}"
