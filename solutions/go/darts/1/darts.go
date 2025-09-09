// Package darts helps calculate scores for the game of darts.
package darts

import "math"

// Score returns the score earned by a dart throw.
func Score(x, y float64) int {
	switch dist := math.Sqrt(math.Pow(x, 2) + math.Pow(y, 2)); {
	case dist <= 1:
		return 10
	case dist <= 5:
		return 5
	case dist <= 10:
		return 1
	default:
		return 0
	}
}
