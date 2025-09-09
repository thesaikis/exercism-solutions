package twelve

import "fmt"

var days = map[int]string{
	1:  "first",
	2:  "second",
	3:  "third",
	4:  "fourth",
	5:  "fifth",
	6:  "sixth",
	7:  "seventh",
	8:  "eighth",
	9:  "ninth",
	10: "tenth",
	11: "eleventh",
	12: "twelfth",
}

var verses = map[int]string{
	1:  "Partridge in a Pear Tree",
	2:  "two Turtle Doves",
	3:  "three French Hens",
	4:  "four Calling Birds",
	5:  "five Gold Rings",
	6:  "six Geese-a-Laying",
	7:  "seven Swans-a-Swimming",
	8:  "eight Maids-a-Milking",
	9:  "nine Ladies Dancing",
	10: "ten Lords-a-Leaping",
	11: "eleven Pipers Piping",
	12: "twelve Drummers Drumming",
}

// Verse returns the ith verse in the song "The Twelve Days of Christmas".
func Verse(i int) string {
	verseStr := fmt.Sprintf("On the %s day of Christmas my true love gave to me: ", days[i])

	for verseNum := i; verseNum > 1; verseNum-- {
		verseStr += verses[verseNum] + ", "
	}

	if i == 1 {
		return verseStr + "a " + verses[1] + "."
	}

	return verseStr + "and a " + verses[1] + "."
}

// Song returns the whole "The Twelve Days of Christmas" lyrics.
func Song() (song string) {
	for i := 1; i < len(verses); i++ {
		song += Verse(i) + "\n"
	}

	song += Verse(len(verses))
	return
}
