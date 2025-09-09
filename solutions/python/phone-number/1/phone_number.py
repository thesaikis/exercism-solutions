class PhoneNumber:
    __banned_punct = "@:!"
    __banned_area_exchange = "01"
    __country_code = 0
    __area_code = 0
    __exchange_code = 3

    def __init__(self, number):
        if any(c.isalpha() for c in number):
            raise ValueError("letters not permitted")
        if any(c in PhoneNumber.__banned_punct for c in number):
            raise ValueError("punctuations not permitted")

        number = "".join(c for c in number if c.isdigit())

        if len(number) < 10:
            raise ValueError("must not be fewer than 10 digits")
        if len(number) > 11:
            raise ValueError("must not be greater than 11 digits")

        if len(number) == 11:
            if number[PhoneNumber.__country_code] != "1":
                raise ValueError("11 digits must start with 1")
            number = number[PhoneNumber.__country_code + 1 :]

        if number[PhoneNumber.__area_code] in PhoneNumber.__banned_area_exchange:
            raise ValueError(
                "area code cannot start with "
                + ("one" if number[PhoneNumber.__area_code] == "1" else "zero")
            )
        if number[PhoneNumber.__exchange_code] in PhoneNumber.__banned_area_exchange:
            raise ValueError(
                "exchange code cannot start with "
                + ("one" if number[PhoneNumber.__exchange_code] == "1" else "zero")
            )

        self.number = number
        self.area_code = number[: PhoneNumber.__exchange_code]

    def pretty(self):
        return f"({self.number[:3]})-{self.number[3:6]}-{self.number[6:]}"
