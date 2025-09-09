// Package collatzconjecture provides a function for the Collatz Conjecture.
package collatzconjecture

import "errors"

// CollatzConjecture returns the number of steps it takes to each 1 while
// applying the operations of the conjecture to a given positive integer
func CollatzConjecture(n int) (steps int, err error) {
	if n <= 0 {
		return 0, errors.New("not a positive integer")
	}

	for ; n > 1; steps++ {
		if n%2 == 0 {
			n /= 2
		} else {
			n = n*3 + 1
		}
	}

	return
}
