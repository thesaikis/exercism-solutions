// Package pangram implements a function to determine if a sentence is a pangram.
package pangram

import "unicode"

// IsPangram determines if a sentence is a pangram.
func IsPangram(input string) bool {
	lettersFound := make([]bool, 26)

	for _, char := range input {
		if unicode.IsLetter(unicode.ToLower(char)) {
			lettersFound[unicode.ToLower(char)-'a'] = true
		}
	}

	for _, found := range lettersFound {
		if !found {
			return false
		}
	}

	return true
}
