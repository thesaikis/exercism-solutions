// Package raindrops provides a function to turn an int into a special string.
package raindrops

import "strconv"

// Convert returns a combination of "Pling", "Plang", and "Plong" depending
// if the given number is divisible by 3, 5, or 7.
func Convert(number int) (res string) {
	if number%3 == 0 {
		res += "Pling"
	}
	if number%5 == 0 {
		res += "Plang"
	}
	if number%7 == 0 {
		res += "Plong"
	}

	if res == "" {
		return strconv.Itoa(number)
	}

	return res
}
