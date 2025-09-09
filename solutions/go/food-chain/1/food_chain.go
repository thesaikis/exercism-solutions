package foodchain

import (
	"strings"
)

type verseDataObj struct {
	animalName string
	quip       string
	eatenName  string
}

var verseData = []verseDataObj{
	{animalName: "fly", quip: "I don't know why she swallowed the fly. Perhaps she'll die.", eatenName: ""},
	{animalName: "spider", quip: "It wriggled and jiggled and tickled inside her.", eatenName: "fly"},
	{animalName: "bird", quip: "How absurd to swallow a bird!", eatenName: "spider that wriggled and jiggled and tickled inside her"},
	{animalName: "cat", quip: "Imagine that, to swallow a cat!", eatenName: "bird"},
	{animalName: "dog", quip: "What a hog, to swallow a dog!", eatenName: "cat"},
	{animalName: "goat", quip: "Just opened her throat and swallowed a goat!", eatenName: "dog"},
	{animalName: "cow", quip: "I don't know how she swallowed a cow!", eatenName: "goat"},
	{animalName: "horse", quip: "She's dead, of course!", eatenName: ""},
}

// Verse returns the vth verse of the song.
func Verse(v int) string {
	var sb strings.Builder
	v -= 1

	sb.WriteString("I know an old lady who swallowed a " + verseData[v].animalName + ".\n" + verseData[v].quip)
	if verseData[v].eatenName != "" {
		for ; v > 0; v-- {
			sb.WriteString("\nShe swallowed the " + verseData[v].animalName + " to catch the " + verseData[v].eatenName + ".")
		}
		sb.WriteString("\n" + verseData[v].quip)
	}

	return sb.String()
}

// Verses returns the verses in the start to end range.
func Verses(start, end int) string {
	var sb strings.Builder

	for ; start <= end; start++ {
		sb.WriteString(Verse(start) + "\n\n")
	}

	return sb.String()[:sb.Len()-2]
}

// Song returns the whole song.
func Song() string {
	return Verses(1, 8)
}
