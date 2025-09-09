package summultiples

// SumMultiples returns the sum of all unique multiples of the given divisors.
func SumMultiples(limit int, divisors ...int) int {
	freqMap := make(map[int]int)
	sum := 0

	for _, div := range divisors {
		for i := div; i < limit && i != 0; i += div {
			freqMap[i]++
			if freqMap[i] == 1 {
				sum += i
			}
		}
	}

	return sum
}
