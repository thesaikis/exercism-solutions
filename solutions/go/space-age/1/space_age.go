// Package space provides a function to calculate a persons age on a different planet.
package space

type Planet string

var orbPeriods = map[string]float64{
	"Mercury": 0.24084657,
	"Venus":   0.61519726,
	"Earth":   1.0,
	"Mars":    1.8808158,
	"Jupiter": 11.862615,
	"Saturn":  29.447498,
	"Uranus":  84.016846,
	"Neptune": 164.79132,
}

// Age returns the persons age in years on the planet given their age in seconds.
func Age(seconds float64, planet Planet) float64 {
	orbPeriod, ok := orbPeriods[string(planet)]

	if !ok {
		return -1
	}
	return seconds / orbPeriod / 60 / 60 / 24 / 365.25
}
