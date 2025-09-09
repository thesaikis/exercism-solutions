package prime

// Factors retunrs a list of the prime factors of the given integer.
func Factors(n int64) []int64 {
	primeFactors := make([]int64, 0)

	for n > 1 {
		var i int64
		for i = 2; i*i <= n; i += 1 {
			if n%i == 0 {
				primeFactors = append(primeFactors, i)
				n /= i
				break
			}

		}
		if i*i > n {
			primeFactors = append(primeFactors, n)
			break
		}
	}

	return primeFactors
}
