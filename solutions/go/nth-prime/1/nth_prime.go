package prime

import (
	"errors"
	"math"
)

// Nth returns the nth prime number. An error must be returned if the nth prime number can't be calculated ('n' is equal or less than zero)
func Nth(n int) (int, error) {
	if n < 1 {
		return 0, errors.New("cannot find nth prime if n < 1")
	} else if n == 1 {
		return 2, nil
	}

	primesFound := 1
	i := 3

	for ; primesFound < n; i += 2 {
		if isPrime(i) {
			primesFound++
			if primesFound == n {
				break
			}
		}
	}

	return i, nil
}

// isPrime returns true if n is prime.
func isPrime(n int) bool {
	for i := 2; i <= int(math.Floor(math.Sqrt(float64(n)))); i++ {
		if n%i == 0 {
			return false
		}
	}

	return true
}
