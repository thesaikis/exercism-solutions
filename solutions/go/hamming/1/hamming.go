// Pacakge hamming provides a function for finding the Hamming Distance.
package hamming

import "errors"

// Distance returns the Hamming Distance between two strands of DNA represented
// as strings, and an error if they are not the same length.
func Distance(a, b string) (dist int, _ error) {
	if len(a) != len(b) {
		return 0, errors.New("DNA sequence length not the same")
	}

	for index := range a {
		if a[index] != b[index] {
			dist++
		}
	}

	return
}
