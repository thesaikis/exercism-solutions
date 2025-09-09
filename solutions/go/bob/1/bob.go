// Package bob implements a function to determine bob's response.
package bob

import (
	"strings"
	"unicode"
	"unicode/utf8"
)

// Hey returns bob's response to the given remark.
func Hey(remark string) string {
	remark = strings.TrimSpace(remark)
	isRemarkUpper := isAllUppercase(remark)
	lastChar, _ := utf8.DecodeLastRuneInString(remark)

	switch {
	case remark == "":
		return "Fine. Be that way!"
	case isRemarkUpper && lastChar == '?':
		return "Calm down, I know what I'm doing!"
	case lastChar == '?':
		return "Sure."
	case isRemarkUpper:
		return "Whoa, chill out!"
	default:
		return "Whatever."
	}
}

func isAllUppercase(input string) bool {
	hasLetter := false

	for _, char := range input {
		if unicode.IsLetter(char) {
			hasLetter = true
			if !unicode.IsUpper(char) {
				return false
			}
		}
	}

	return hasLetter
}
