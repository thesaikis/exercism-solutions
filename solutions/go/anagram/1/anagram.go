package anagram

import (
	"sort"
	"strings"
)

// Detect returns a list of words from candidates that are anagrams to the given subject.
func Detect(subject string, candidates []string) []string {
	res := make([]string, 0)

	subLower := strings.ToLower(subject)
	splitStr := strings.Split(subLower, "")
	sort.Strings(splitStr)
	sortedStr := strings.Join(splitStr, "")

	for _, candidate := range candidates {
		candLower := strings.ToLower(candidate)
		splitCand := strings.Split(candLower, "")
		sort.Strings(splitCand)
		sortedCand := strings.Join(splitCand, "")

		if sortedStr == sortedCand && subLower != candLower {
			res = append(res, candidate)
		}
	}

	return res
}
