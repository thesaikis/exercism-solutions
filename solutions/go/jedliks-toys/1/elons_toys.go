// Package elon provides methods for cars.
package elon

import "fmt"

// Drive reduces the car's battery by the battery drain amount and increases the
// distance based on the car's speed.
func (car *Car) Drive() {
	if car.battery-car.batteryDrain < 0 {
		return
	}

	car.battery -= car.batteryDrain
	car.distance += car.speed
}

// DisplayDistance returns a string containing the current distance driven by the car.
func (car Car) DisplayDistance() string {
	return fmt.Sprintf("Driven %d meters", car.distance)
}

// DisplayBattery returns as tring containing the current battery percentage of the car.
func (car Car) DisplayBattery() string {
	return fmt.Sprintf("Battery at %d%%", car.battery)
}

// CanFinish determines if the car can finish the track without running out of battery.
func (car Car) CanFinish(trackDistance int) bool {
	return car.battery/car.batteryDrain*car.speed >= trackDistance
}
