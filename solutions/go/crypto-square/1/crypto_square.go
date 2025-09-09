package cryptosquare

import (
	"math"
	"strings"
	"unicode"
)

// Encode turns the given message into an encoded message using square code.
func Encode(pt string) string {
	var validStringBuilder strings.Builder

	for _, char := range pt {
		if unicode.IsLetter(char) || unicode.IsDigit(char) {
			validStringBuilder.WriteRune(unicode.ToLower(char))
		}
	}

	validString := validStringBuilder.String()

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
