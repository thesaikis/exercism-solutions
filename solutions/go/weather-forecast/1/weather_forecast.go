// Package weather provides a function that
// prints information about the weather condition.
package weather

// CurrentCondition represents the current weather condition as a string.
var CurrentCondition string

// CurrentLocation represents the current city or location as a string.
var CurrentLocation string

// Forecast returns a string that combines the given city and condition.
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}
