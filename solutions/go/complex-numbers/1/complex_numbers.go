package complexnumbers

import "math"

type Number struct {
	a, b float64
}

// Real returns the real value of a complex number.
func (n Number) Real() float64 {
	return n.a
}

// Imaginary returns the imaginary value of a complex number.
func (n Number) Imaginary() float64 {
	return n.b
}

// Add returns the result of addition on two complex numbers.
func (n1 Number) Add(n2 Number) Number {
	return Number{
		a: n1.Real() + n2.Real(),
		b: n1.Imaginary() + n2.Imaginary(),
	}
}

// Subtract returns the result of subtraction on two complex numbers.
func (n1 Number) Subtract(n2 Number) Number {
	return Number{
		a: n1.Real() - n2.Real(),
		b: n1.Imaginary() - n2.Imaginary(),
	}
}

// Multiply returns the result of multiplication on two complex numbers.
func (n1 Number) Multiply(n2 Number) Number {
	return Number{
		a: n1.Real()*n2.Real() - n1.Imaginary()*n2.Imaginary(),
		b: n1.Imaginary()*n2.Real() + n1.Real()*n2.Imaginary(),
	}
}

// Times returns the result of multiplication with a complex number and a scalar value.
func (n Number) Times(factor float64) Number {
	return Number{
		a: n.Real() * factor,
		b: n.Imaginary() * factor,
	}
}

// Divide returns the result of division on two complex numbers.
func (n1 Number) Divide(n2 Number) Number {
	return Number{
		a: (n1.Real()*n2.Real() + n1.Imaginary()*n2.Imaginary()) / (n2.Real()*n2.Real() + n2.Imaginary()*n2.Imaginary()),
		b: (n1.Imaginary()*n2.Real() - n1.Real()*n2.Imaginary()) / (n2.Real()*n2.Real() + n2.Imaginary()*n2.Imaginary()),
	}
}

// Conjugate returns the conjugate of a complex number.
func (n Number) Conjugate() Number {
	return Number{
		a: n.Real(),
		b: -n.Imaginary(),
	}
}

// Abs returns the absolute value of a complex number.
func (n Number) Abs() float64 {
	return math.Sqrt(n.Multiply(n.Conjugate()).Real())
}

// Exp returns e raised to the power of a complex number.
func (n Number) Exp() Number {
	return Number{
		a: math.Pow(math.E, n.Real()) * math.Cos(n.Imaginary()),
		b: math.Pow(math.E, n.Real()) * math.Sin(n.Imaginary()),
	}
}
