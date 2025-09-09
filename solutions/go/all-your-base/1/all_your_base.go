package allyourbase

import (
	"errors"
	"math"
)

// ConverToBase converts the given input, seperate into each digit, into a different base.
func ConvertToBase(inputBase int, inputDigits []int, outputBase int) ([]int, error) {
	if inputBase < 2 {
		return nil, errors.New("input base must be >= 2")
	} else if outputBase < 2 {
		return nil, errors.New("output base must be >= 2")
	}

	outNum := 0

	for idx, num := range inputDigits {
		if num < 0 || num >= inputBase {
			return nil, errors.New("all digits must satisfy 0 <= d < input base")
		}
		outNum += num * int(math.Pow(float64(inputBase), float64(len(inputDigits)-idx-1)))
	}

	if outNum == 0 || len(inputDigits) == 0 {
		return []int{0}, nil
	}

	outputDigits := []int{}

	for exp := int(math.Log(float64(outNum)) / math.Log(float64(outputBase))); exp >= 0; exp-- {
		divisor := int(math.Pow(float64(outputBase), float64(exp)))
		digit := outNum / divisor
		outputDigits = append(outputDigits, digit)
		outNum %= divisor
	}

	return outputDigits, nil
}
