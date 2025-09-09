package resistorcolortrio

import (
	"fmt"
	"math"
)

const (
	giga = 1000000000
	mega = 1000000
	kilo = 1000
)

var resistances = map[string]int{
	"black":  0,
	"brown":  1,
	"red":    2,
	"orange": 3,
	"yellow": 4,
	"green":  5,
	"blue":   6,
	"violet": 7,
	"grey":   8,
	"white":  9,
}

// Label returns the resistance value for a given resistor label.
func Label(colors []string) string {
	resistance := (resistances[colors[0]]*10 + resistances[colors[1]]) * int(math.Pow(10, float64(resistances[colors[2]])))
	metric := "ohms"

	if resistance/giga > 0 {
		resistance /= giga
		metric = "gigaohms"
	} else if resistance/mega > 0 {
		resistance /= mega
		metric = "megaohms"
	} else if resistance/kilo > 0 {
		resistance /= kilo
		metric = "kiloohms"
	}

	return fmt.Sprintf("%d %s", resistance, metric)
}
