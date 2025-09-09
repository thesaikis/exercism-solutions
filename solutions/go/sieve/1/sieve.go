package sieve

// Sieve returns the all primes up to the given limit.
func Sieve(limit int) []int {
	primes := make([]int, 0)
	isComposite := make([]bool, limit-1)

	for i := 2; i*i <= limit; i++ {
		if !isComposite[i-2] {
			for j := i * i; j <= limit; j += i {
				isComposite[j-2] = true
			}
		}
	}

	for idx, b := range isComposite {
		if !b {
			primes = append(primes, idx+2)
		}
	}

	return primes
}
