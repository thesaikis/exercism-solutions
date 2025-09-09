package cipher

import (
	"strings"
	"unicode"
)

type shift struct {
	key int
}

type vigenere struct {
	key []rune
}

const (
	encodeOp = iota
	decodeOp
)

// NewCaesar returns a new Cipher which shifts by 3.
func NewCaesar() Cipher {
	return NewShift(3)
}

// NewShift returns a new Chipher with shifts by the given distance.
func NewShift(distance int) Cipher {
	if distance <= -26 || distance == 0 || distance >= 26 {
		return nil
	}

	return shift{
		key: distance,
	}
}

// Encode returns the encoded input which uses shifting.
func (c shift) Encode(input string) string {
	return strings.Map(func(r rune) rune {
		if !unicode.IsLetter(r) {
			return -1
		}

		r += rune(c.key)

		if r > 'z' {
			r = 'a' + (r - 'z') - 1
		} else if r < 'a' {
			r = 'z' - ('a' - r) + 1
		}

		return r
	}, strings.ToLower(input))
}

// Decode returns the decoded input which uses shifting.
func (c shift) Decode(input string) string {
	return NewShift(-c.key).Encode(input)
}

// NewVigenere returns a new Cipher which shifts using the given key.
func NewVigenere(key string) Cipher {
	if len(key) < 3 {
		return nil
	}

	for _, char := range key {
		if !unicode.IsLetter(char) || !unicode.IsLower(char) {
			return nil
		}
	}

	return vigenere{
		key: []rune(key),
	}
}

// Encode returns the encoded input using a substitution cipher.
func (v vigenere) Encode(input string) string {
	return v.process(input, encodeOp)
}

// Decode returns the decoded input using a substitution cipher.
func (v vigenere) Decode(input string) string {
	return v.process(input, decodeOp)
}

func (v vigenere) process(input string, op int) string {
	res := ""
	keyIdx := 0

	for _, char := range strings.ToLower(input) {
		if !unicode.IsLetter(char) {
			continue
		}

		switch op {
		case encodeOp:
			char += v.key[keyIdx] - 'a'
			if char > 'z' {
				char = 'a' + (char - 'z') - 1
			}
		case decodeOp:
			char -= v.key[keyIdx] - 'a'
			if char < 'a' {
				char = 'z' - ('a' - char) + 1
			}
		}

		res += string(char)

		keyIdx += 1
		if keyIdx >= len(v.key) {
			keyIdx = 0
		}
	}

	return string(res)
}
