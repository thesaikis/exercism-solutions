package armstrong

import "math"

// IsNumber returns true is the given integer is an Armstrong number.
func IsNumber(n int) bool {
	numberLen := math.Floor(math.Log10(float64(n))) + 1
	sum := 0
	orig := n

	for n > 0 {
		sum += int(math.Pow(float64(n%10), float64(numberLen)))
		n /= 10
	}

	return sum == orig
}
