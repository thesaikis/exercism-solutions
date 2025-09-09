package grep

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

// Search returns the lines/files where the pattern is found depending on the arguments.
func Search(pattern string, flags, files []string) []string {
	var prependLines, onlyNames, caseInsensitive, invert, entireLine bool
	var matches []string

	for _, flag := range flags {
		switch flag {
		case "-n":
			prependLines = true
		case "-l":
			onlyNames = true
		case "-i":
			caseInsensitive = true
		case "-v":
			invert = true
		case "-x":
			entireLine = true
		}
	}

	if caseInsensitive {
		pattern = strings.ToLower(pattern)
	}

	for _, fileName := range files {
		file, _ := os.Open(fileName)
		scanner := bufio.NewScanner(file)

		lineNum := 1
		for scanner.Scan() {
			line := scanner.Text()

			if caseInsensitive {
				line = strings.ToLower(line)
			}

			match := ((entireLine && strings.EqualFold(line, pattern)) || (!entireLine && strings.Contains(line, pattern)))

			if invert {
				match = !match
			}

			if onlyNames && match {
				matches = append(matches, fileName)
				break
			} else if match {
				line = scanner.Text()
				if prependLines {
					line = strconv.Itoa(lineNum) + ":" + line
				}
				if len(files) > 1 {
					line = fileName + ":" + line
				}
				matches = append(matches, line)
			}

			lineNum++
		}
		file.Close()
	}

	return matches
}
