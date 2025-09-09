package bottlesong

import (
	"fmt"
	"strings"
)

var intToStr = map[int]string{
	0: "no", 1: "one", 2: "two", 3: "three", 4: "four",
	5: "five", 6: "six", 7: "seven", 8: "eight", 9: "nine", 10: "ten",
}

// Recite returns the verses of the Ten Green Bottles song given the
// number of starting bottles and how many to take down.
func Recite(startBottles, takeDown int) []string {
	verses := make([]string, 0)

	for i := 0; i < takeDown; i++ {
		verses = append(verses, []string{
			fmt.Sprintf("%s green %s hanging on the wall,", strings.Title(intToStr[startBottles]), bottlesPlural(startBottles)),
			fmt.Sprintf("%s green %s hanging on the wall,", strings.Title(intToStr[startBottles]), bottlesPlural(startBottles)),
			"And if one green bottle should accidentally fall,",
			fmt.Sprintf("There'll be %s green %s hanging on the wall.", intToStr[startBottles-1], bottlesPlural(startBottles-1)),
			"",
		}...)
		startBottles -= 1
	}

	return verses[:len(verses)-1]
}

func bottlesPlural(bottles int) string {
	if bottles == 1 {
		return "bottle"
	}
	return "bottles"
}
