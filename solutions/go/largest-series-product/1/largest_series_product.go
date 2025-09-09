package lsproduct

import "errors"

// LargestSeriesProduct returns the largest product of length span from digits.
func LargestSeriesProduct(digits string, span int) (int64, error) {
	if len(digits) < span {
		return 0, errors.New("span must be smaller than string length")
	} else if span < 0 {
		return 0, errors.New("span cannot be negative")
	}

	var max int64 = 0

	for i := 0; i < len(digits) - span + 1; i++ {
		if digits[i] < '0' || digits[i] > '9' {
			return 0, errors.New("digits input must only contain digits")
		}

		curProd := int64(digits[i] - '0')

		for j := 1; j < span; j++ {
			curProd *= int64(digits[i + j] - '0')
		}

		if curProd > max {
			max = curProd
		}
	}

	return max, nil
}
