// Package romannumerals implements a function for roman numerals.
package romannumerals

import "errors"

var numerals = []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
var values = []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}

// ToRomanNumeral converts a base 10 number into a roman numeral.
func ToRomanNumeral(input int) (result string, _ error) {
	if input < 1 || input > 3999 {
		return "", errors.New("input out of roman numeral range")
	}

	for i := 0; i < len(numerals); i++ {
		for input >= values[i] {
			result += numerals[i]
			input -= values[i]
		}
	}

	return
}
