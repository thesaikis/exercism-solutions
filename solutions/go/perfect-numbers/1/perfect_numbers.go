package perfect

import "errors"

type Classification int

const (
	ClassificationDeficient Classification = iota
	ClassificationPerfect
	ClassificationAbundant
)

var ErrOnlyPositive = errors.New("given number was not positive")

func Classify(n int64) (Classification, error) {
	if n <= 0 {
		return 0, ErrOnlyPositive
	}

	var sum int64
	for i := int64(1); i <= n/2; i++ {
		if n%i == 0 {
			sum += i
		}
	}

	if sum == n {
		return ClassificationPerfect, nil
	} else if sum > n {
		return ClassificationAbundant, nil
	}
	return ClassificationDeficient, nil
}
