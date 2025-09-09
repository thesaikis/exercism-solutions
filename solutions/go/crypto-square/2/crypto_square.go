package cryptosquare

import (
	"math"
	"strings"
	"unicode"
)

// Encode turns the given message into an encoded message using square code.
func Encode(pt string) string {
	validString := strings.Map(func(r rune) rune {
		if unicode.IsLetter(r) || unicode.IsDigit(r) {
			return unicode.ToLower(r)
		}
		return -1
	}, pt)

	c := int(math.Sqrt(float64(len(validString))))
	r := c
	if c*c != len(validString) {
		c++
		if c*r < len(validString) {
			r++
		}
	}

	var finalBuilder strings.Builder

	for i := 0; i < c; i++ {
		for j := i; j < r*c; j += c {
			if j >= len(validString) {
				finalBuilder.WriteRune(' ')
			} else {
				finalBuilder.WriteByte(validString[j])
			}
		}
		if i < c-1 {
			finalBuilder.WriteRune(' ')
		}
	}

	return finalBuilder.String()
}
