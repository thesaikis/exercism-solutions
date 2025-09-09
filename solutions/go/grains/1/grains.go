// Package grains implements functions for calculating the number of grains of
// wheat on a chessboard.
package grains

import "errors"

// Square returns the number of grains of wheat on the given chessboard square.
func Square(number int) (uint64, error) {
	if number < 1 || number > 64 {
		return 0, errors.New("invalid square")
	}
	
	var square uint64 = 1

	for i := 1; i < number; i++ {
		square += square
	}

	return square, nil
}

// Total returns the total number of grains of wheat accross the whole chessboard.
func Total() (sum uint64) {
	for i := 1; i <= 64; i++ {
		square, _ := Square(i)
		sum += square
	}

	return
}
