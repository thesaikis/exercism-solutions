// Package isbn provides a function for checking isbn.
package isbn

import (
	"strings"
	"unicode"
)

// IsValidISBN returns whether or not the given isbn-10 is valid.
func IsValidISBN(isbn string) bool {
	mult := 10
	sum := 0

	if strings.HasSuffix(isbn, "X") {
		isbn = strings.Replace(isbn, "X", "0", -1)
		sum += 10
	}

	if len(isbn) < 10 || !unicode.IsDigit(rune(isbn[len(isbn)-1])) {
		return false
	}

	for _, char := range isbn {
		if unicode.IsDigit(char) {
			sum += mult * int(char-'0')
			mult -= 1
		} else if char != '-' {
			return false
		}
		if mult < 0 {
			return false
		}
	}

	return sum%11 == 0
}
