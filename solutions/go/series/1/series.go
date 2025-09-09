package series

// All returns all the series in the given string with the given length.
func All(n int, s string) (res []string) {
	for i := 0; i < len(s)-n+1; i++ {
		res = append(res, s[i:i+n])
	}

	return
}

// UnsafeFirst returns the first substring of the given string with the given length.
func UnsafeFirst(n int, s string) string {
	return s[:n]
}
