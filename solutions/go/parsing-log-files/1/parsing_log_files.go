// Pacakge parsinglogfiles provides functions for parsing log files.
package parsinglogfiles

import "regexp"

// IsValidLine returns whether or not string begins with a certain tag.
func IsValidLine(text string) bool {
	return regexp.MustCompile(`^\[(TRC|DBG|INF|WRN|ERR|FTL)\]`).MatchString(text)
}

// SplitLogLine returns the given text split into parts using
// a special separator.
func SplitLogLine(text string) []string {
	return regexp.MustCompile(`<[~*=-]*>`).Split(text, -1)
}

// CountQuotedPasswords returns the count of lines including the word
// "password" anywhere within quotation marks.
func CountQuotedPasswords(lines []string) (count int) {
	var re *regexp.Regexp = regexp.MustCompile(`"(?i)[^"]*password[^"]*"`)

	for _, line := range lines {
		if re.MatchString(line) {
			count++
		}
	}

	return
}

// RemoveEndOfLine text removes any occurrence of "end-of-line" followed by
// any amount of digits.
func RemoveEndOfLineText(text string) string {
	return regexp.MustCompile(`end-of-line\d*`).ReplaceAllString(text, "")
}

// TagWithUserName returns logs appened with "[USR] {username}"
// if the phrase "[USR] {username}" is found
func TagWithUserName(lines []string) []string {
	taggedLines := []string{}
	var re *regexp.Regexp = regexp.MustCompile(`User\s+(\w+)`)

	for _, line := range lines {
		matches := re.FindStringSubmatch(line)
		if len(matches) > 1 {
			line = "[USR] " + matches[1] + " " + line
		}
		taggedLines = append(taggedLines, line)
	}

	return taggedLines
}
