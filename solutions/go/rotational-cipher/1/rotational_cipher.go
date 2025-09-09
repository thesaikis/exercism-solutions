// Package rotationalcipher implements a function that does a rotational cipher.
package rotationalcipher

import (
	"strings"
	"unicode"
)

// RotationalCipher returns the ROT cipher given the key and the plaintext string.
func RotationalCipher(plain string, shiftKey int) string {
	var sb strings.Builder

	for _, char := range plain {
		if unicode.IsLetter(char) {
			if unicode.IsUpper(char) {
				sb.WriteRune((char-'A'+rune(shiftKey))%26 + 'A')
			} else {
				sb.WriteRune((char-'a'+rune(shiftKey))%26 + 'a')
			}
		} else {
			sb.WriteRune(char)
		}
	}

	return sb.String()
}
