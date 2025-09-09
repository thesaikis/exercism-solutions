package wordy

import (
	"regexp"
	"strconv"
	"strings"
)

// Answer parses the given math word problem and returns the answer.
func Answer(question string) (int, bool) {
	var re regexp.Regexp = *regexp.MustCompile(`^What is (-?[0-9]+)\?*`)
	var initialQuestionMatch []string = re.FindStringSubmatch(question)
	var initialValue int = 0

	if len(initialQuestionMatch) > 0 {
		initialValue, _ = strconv.Atoi(initialQuestionMatch[1])
		question = strings.TrimSpace(strings.Replace(question, initialQuestionMatch[0], "", 1))
	} else {
		return 0, false
	}

	if len(question) == 0 {
		return initialValue, true
	}

	var opRe regexp.Regexp = *regexp.MustCompile(`^(plus|minus|multiplied by|divided by) (-?[0-9]+)\?*`)

	for len(question) > 0 {
		var operationMatch []string = opRe.FindStringSubmatch(question)

		if len(operationMatch) < 2 {
			return 0, false
		}

		opVal, _ := strconv.Atoi(operationMatch[2])
		switch operationMatch[1] {
		case "plus":
			initialValue += opVal
		case "minus":
			initialValue -= opVal
		case "multiplied by":
			initialValue *= opVal
		case "divided by":
			initialValue /= opVal
		}

		question = strings.TrimSpace(strings.Replace(question, operationMatch[0], "", 1))
	}

	return initialValue, true
}
