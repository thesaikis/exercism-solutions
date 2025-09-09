package triangle

type Kind int

const (
	NaT = iota
	Equ
	Iso
	Sca
)

// KindFromSides returns the type of triangle given the lengths of the three sides.
func KindFromSides(a, b, c float64) Kind {
	if a+b < c || b+c < a || a+c < b || a <= 0 || b <= 0 || c <= 0 {
		return NaT
	}

	switch {
	case a == b && b == c && a == c:
		return Equ
	case a != b && b != c && a != c:
		return Sca
	default:
		return Iso
	}
}
