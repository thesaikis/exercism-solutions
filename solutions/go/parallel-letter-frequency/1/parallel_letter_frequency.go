package letter

// FreqMap records the frequency of each rune in a given text.
type FreqMap map[rune]int

// Frequency counts the frequency of each rune in a given text and returns this
// data as a FreqMap.
func Frequency(text string) FreqMap {
	fm := FreqMap{}
	for _, r := range text {
		fm[r]++
	}

	return fm
}

// ConcurrentFrequency counts the frequency of each rune in the given strings,
// by making use of concurrency.
func ConcurrentFrequency(texts []string) FreqMap {
	freqMap := FreqMap{}
	c := make(chan FreqMap)

	for _, text := range texts {
		go func(text string) {
			c <- Frequency(text)
		}(text)
	}

	for range texts {
		fm := <- c
		for char, freq := range fm {
			freqMap[char] += freq
		}
	}

	return freqMap
}
