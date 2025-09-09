// Package reverse implements a function to reverse a string.
package reverse

import "unicode/utf8"

// Reverse returns the reversed input string.
func Reverse(input string) string {
	asRunes := make([]rune, utf8.RuneCountInString(input))
	index := len(asRunes) - 1

	for len(input) > 0 {
		r, size := utf8.DecodeRuneInString(input)
		asRunes[index] = r
		index -= 1
		input = input[size:]
	}

	return string(asRunes)
}
