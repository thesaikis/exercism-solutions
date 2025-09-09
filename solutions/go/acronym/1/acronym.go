package acronym

import (
	"regexp"
	"strings"
)

// Abbreviate returns the acronym of the given string.
func Abbreviate(s string) string {
	return strings.ToUpper(regexp.MustCompile(`(?:\b_*|-*)(\w)(?:(\w|')*)(?:\s|,|-)*`).ReplaceAllString(s, "$1"))
}
