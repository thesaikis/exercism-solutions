// Package luhn solves the Luhn exercise from Exercism.
package luhn

import (
	"strings"
	"unicode"
)

// Valid returns true if the given id is valid per the Luhn formula,
// returns false otherwise.
func Valid(id string) bool {
	id = strings.ReplaceAll(id, " ", "")

	if len(id) <= 1 {
		return false
	}

	var sum int

	for idx, c := range id {
		if !unicode.IsDigit(c) {
			return false
		}

		switch (len(id) - 1 - idx) % 2 {
		case 0:
			sum += int(c - '0')
		default:
			sum += int(c-'0')*2 - 9*(int(c-'0')*2/10)
		}
	}

	return sum%10 == 0
}
