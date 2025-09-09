package encode

import (
	"regexp"
	"strconv"
	"strings"
)

func writeToSb(sb *strings.Builder, count int, curChar rune) {
	if count != 1 {
		sb.WriteString(strconv.Itoa(count))
	}
	sb.WriteRune(curChar)
}

func RunLengthEncode(input string) string {
	if input == "" {
		return ""
	}

	var sb strings.Builder
	var curChar rune
	count := -1

	for _, char := range input {
		if count == -1 {
			count = 1
			curChar = char
			continue
		} else if curChar != char {
			writeToSb(&sb, count, curChar)
			count = 1
			curChar = char
			continue
		}
		count++
	}

	writeToSb(&sb, count, curChar)

	return sb.String()
}

func RunLengthDecode(input string) string {
	re := regexp.MustCompile(`(\d*)(\w|\s{1})`)
	var sb strings.Builder

	for _, match := range re.FindAllStringSubmatch(input, -1) {
		amount := 1
		if len(match[1]) > 0 {
			amount, _ = strconv.Atoi(match[1])
		}

		for i := 0; i < amount; i++ {
			sb.WriteString(match[2])
		}
	}

	return sb.String()
}
