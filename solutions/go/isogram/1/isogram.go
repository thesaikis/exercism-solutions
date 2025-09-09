// Package isogram solves the Isogram exercism on exercism.
package isogram

import "strings"

// IsIsogram returns true if the given word is an isograme, false otherwise.
func IsIsogram(word string) bool {
	lettersFound := make([]bool, 26)

	for _, c := range strings.ToLower(word) {
		if c < 'a' || c > 'z' {
			continue
		}
		if lettersFound[c-'a'] {
			return false
		}
		lettersFound[c-'a'] = true
	}

	return true
}
