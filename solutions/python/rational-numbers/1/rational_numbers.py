from math import gcd


class Rational:
    def __init__(self, numer, denom):
        self.numer = numer
        self.denom = denom
        self.reduce()

    def reduce(self):
        common_divisor = gcd(self.numer, self.denom)
        self.numer //= common_divisor
        self.denom //= common_divisor
        if self.denom < 0:  # Ensure the denominator is positive
            self.numer = -self.numer
            self.denom = -self.denom

    def __eq__(self, other):
        return self.numer == other.numer and self.denom == other.denom

    def __repr__(self):
        return f"{self.numer}/{self.denom}"

    def __add__(self, other):
        return Rational(
            (self.numer * other.denom + other.numer * self.denom),
            (self.denom * other.denom),
        )

    def __sub__(self, other):
        return Rational(
            (self.numer * other.denom - other.numer * self.denom),
            (self.denom * other.denom),
        )

    def __mul__(self, other):
        return Rational((self.numer * other.numer), (self.denom * other.denom))

    def __truediv__(self, other):
        return Rational((self.numer * other.denom), (other.numer * self.denom))

    def __abs__(self):
        return Rational(abs(self.numer), abs(self.denom))

    def __pow__(self, power):
        if power > 0:
            return Rational(pow(self.numer, power), pow(self.denom, power))
        else:
            return Rational(pow(self.denom, -power), pow(self.numer, -power))

    def __rpow__(self, base):
        return pow(base, self.numer) ** (1 / self.denom)
