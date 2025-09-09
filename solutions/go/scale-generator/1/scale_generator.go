package scale

import (
	"strings"
)

type MScale []string

var chromaticScaleSharp = MScale{"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"}
var chromaticScaleFlat = MScale{"A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab"}

var flatTonics = []string{"F", "Bb", "Eb", "Ab", "Db", "Gb", "d", "g", "c", "f", "bb", "eb"}

// Scale returns the scale with the given interval, starting at the given tonic.
func Scale(tonic, interval string) []string {
	if interval == "" {
		interval = "mmmmmmmmmmm"
	}

	flatMode := MScale(flatTonics).Index(tonic) != -1
	tonic = strings.Title(tonic)
	scale := MScale{tonic}

	var chromaticScale MScale
	if flatMode {
		chromaticScale = chromaticScaleFlat
	} else {
		chromaticScale = chromaticScaleSharp
	}

	idx := chromaticScale.Index(tonic)

	for _, step := range interval {
		switch step {
		case 'M':
			idx += 2
		case 'm':
			idx++
		case 'A':
			idx += 3
		}

		idx %= len(chromaticScale)
		scale = append(scale, chromaticScale[idx])
	}

	return scale
}

func (s MScale) Index(str string) int {
	for idx, data := range s {
		if str == data {
			return idx
		}
	}
	return -1
}
