package piglatin

import (
	"regexp"
	"strings"
)

var (
	ruleOne = regexp.MustCompile(`^(?:[aeiou]|xr|yt).+$`)
	ruleTwo = regexp.MustCompile(`^(qu|[^aeiou]+)(.+)$`)
	ruleThree = regexp.MustCompile(`^([^aeiou]qu)(.+)$`)
	ruleFour = regexp.MustCompile(`^([^aeiou]+)(y.*)$`)
)

// Sentence returns the given sentence in Pig Latin.
func Sentence(sentence string) string {
	var finalWords []string

	for _, word := range strings.Split(sentence, " ") {
		if ruleOne.MatchString(word) {
			finalWords = append(finalWords, word + "ay")
		} else if m := ruleFour.FindStringSubmatch(word); len(m) > 0 {
			finalWords = append(finalWords, m[2] + m[1] + "ay")
		} else if m := ruleThree.FindStringSubmatch(word); len(m) > 0 {
			finalWords = append(finalWords, m[2] + m[1] + "ay")
		} else if m := ruleTwo.FindStringSubmatch(word); len(m) > 0 {
			finalWords = append(finalWords, m[2] + m[1] + "ay")
		}
	}

	return strings.Join(finalWords, " ")
}
