// Package purchase provides functions for making decisions related to vehicle purchases and reselling.
//
// The functions in this package help determine whether a license is needed for a particular type of vehicle,
// recommend a choice between two vehicles based on lexicographical order, and calculate the resale price
// of a vehicle based on its original price and age.
package purchase

// NeedsLicense determines whether a license is needed to drive a type of vehicle. Only "car" and "truck" require a license.
func NeedsLicense(kind string) bool {
	return kind == "car" || kind == "truck"	
}

// ChooseVehicle recommends a vehicle for selection. It always recommends the vehicle that comes first in lexicographical order.
func ChooseVehicle(option1, option2 string) string {
	if option1 < option2 {
		return option1 + " is clearly the better choice."
	}
	return option2 + " is clearly the better choice."
}

// CalculateResellPrice calculates how much a vehicle can resell for at a certain age.
func CalculateResellPrice(originalPrice, age float64) float64 {
	if age >= 10 {
		return originalPrice * 0.5
	} else if age > 3 {
		return originalPrice * 0.7
	}
	return originalPrice * 0.8
}
