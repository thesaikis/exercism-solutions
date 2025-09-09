// Package thefarm provides calculation for dividing food amongst cows with error handling.
package thefarm

import (
	"errors"
	"fmt"
)

// DivideFood returns the amount of food to give each cow,
// given a FodderCalculator and the number of cows.
func DivideFood(fd FodderCalculator, cows int) (float64, error) {
	totalFodder, err := fd.FodderAmount(cows)
	factor, err2 := fd.FatteningFactor()

	if err != nil {
		return 0, err
	} else if err2 != nil {
		return 0, err2
	}

	return totalFodder * factor / float64(cows), nil
}

// ValidateInputAndDivideFood returns the amount of food to give each cow and checks
// if the number of cows are valid.
func ValidateInputAndDivideFood(fd FodderCalculator, cows int) (float64, error) {
	if cows < 1 {
		return 0, errors.New("invalid number of cows")
	}

	return DivideFood(fd, cows)
}

type InvalidCowsError struct {
	cows    int
	message string
}

// Error returns the error string for the InvalidCowsError.
func (err *InvalidCowsError) Error() string {
	return fmt.Sprintf("%d cows are invalid: %s", err.cows, err.message)
}

// ValidateNumberOfCows returns an error if the number of cows given is invalid
// (less than or equal to 0).
func ValidateNumberOfCows(cows int) error {
	var errorMessage string

	if cows < 0 {
		errorMessage = "there are no negative cows"
	} else if cows == 0 {
		errorMessage = "no cows don't need food"
	} else {
		return nil
	}

	return &InvalidCowsError{
		cows:    cows,
		message: errorMessage,
	}
}
