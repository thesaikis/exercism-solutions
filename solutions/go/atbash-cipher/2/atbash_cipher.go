package atbash

import (
	"regexp"
	"strings"
)

// Atbash returns the Atbash cipher of the given string.
func Atbash(s string) string {
	return strings.Trim(regexp.MustCompile(`(.{5})`).ReplaceAllString(strings.Map(func(r rune) rune {
		if r >= '0' && r <= '9' { return r }
		return 'a' + ('z' - r)
	}, strings.ReplaceAll(strings.ReplaceAll(strings.ToLower(s), " ", ""), ",", "")), "$1 "), " "+string(rune(173)))
}
