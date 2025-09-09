class Luhn:
    card = ""
    invalid = False

    def __init__(self, card_num):
        self.invalid = any(not (c.isdigit() or c.isspace()) for c in card_num)
        self.card = ''.join(num for num in card_num if num.isdigit())

    def valid(self):
        if self.card == "0" or self.invalid:
            return False

        return sum(num if num <= 9 else num - 9 for i, c in enumerate(reversed(self.card)) if (num := int(c) * 2 if i % 2 else int(c)) or True) % 10 == 0

