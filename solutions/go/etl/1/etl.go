// Package etl implements a function for transforming a map.
package etl

// Transform returns the transformed map where the map is indexed by the character
// rather than the score.
func Transform(in map[int][]string) map[string]int {
	out := make(map[string]int)

	for score, letters := range in {
		for _, char := range letters {
			out[string(char[0] + 32)] = score
		}
	}

	return out
}
