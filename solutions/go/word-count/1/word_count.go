package wordcount

import (
	"regexp"
	"strings"
)

type Frequency map[string]int

// WordCount returns a Frequency which contains the number of times each word appears in the phrase.
func WordCount(phrase string) Frequency {
	res := make(Frequency)
	regex := regexp.MustCompile(`(\w+'\w+)|(\w+)`)

	matches := regex.FindAllString(phrase, -1)

	for _, match := range matches {
		res[strings.ToLower(match)]++
	}

	return res
}
