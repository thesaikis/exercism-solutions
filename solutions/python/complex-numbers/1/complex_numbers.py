from math import sqrt, exp as math_exp, sin, cos


class ComplexNumber:
    def __init__(self, real, imaginary):
        self.real = real
        self.imaginary = imaginary

    def __eq__(self, other):
        return self.real == other.real and self.imaginary == other.imaginary

    def __add__(self, other):
        if isinstance(other, ComplexNumber):
            return ComplexNumber(self.real + other.real, self.imaginary + other.imaginary)

        # Assume other is a real scalar
        return ComplexNumber(self.real + other, self.imaginary)

    def __radd__(self, other):
        return self + other

    def __mul__(self, other):
        if isinstance(other, ComplexNumber):
            new_real = self.real * other.real - self.imaginary * other.imaginary
            new_imaginary = self.imaginary * other.real + self.real * other.imaginary
            return ComplexNumber(new_real, new_imaginary)

        # Assume other is a real scalar
        return ComplexNumber(self.real * other, self.imaginary * other)

    def __rmul__(self, other):
        return self * other

    def __sub__(self, other):
        if isinstance(other, ComplexNumber):
            return ComplexNumber(self.real - other.real, self.imaginary - other.imaginary)

        # Assume other is a real scalar
        return ComplexNumber(self.real - other, self.imaginary)

    def __rsub__(self, other):
        return ComplexNumber(other - self.real, -self.imaginary)

    def __truediv__(self, other):
        if isinstance(other, ComplexNumber):
            denom = other.real ** 2 + other.imaginary ** 2
            numer1 = self.real * other.real + self.imaginary * other.imaginary
            numer2 = self.imaginary * other.real - self.real * other.imaginary
            return ComplexNumber(numer1 / denom, numer2 / denom)

        # Assume other is a real scalar
        return ComplexNumber(self.real / other, self.imaginary / other)

    def __rtruediv__(self, other):
        return ComplexNumber(other, 0) / self

    def __abs__(self):
        return sqrt(self.real ** 2 + self.imaginary ** 2)

    def conjugate(self):
        return ComplexNumber(self.real, -self.imaginary)

    def exp(self):
        e_a = math_exp(self.real)
        return ComplexNumber(e_a * cos(self.imaginary), e_a * sin(self.imaginary))
