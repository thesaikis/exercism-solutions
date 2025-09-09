// Package clock implements function for managing simple clocks.
package clock

import "fmt"

type Clock struct {
	hour   int
	minute int
}

// New returns a new clock given the hours and minutes.
func New(h, m int) Clock {
	total := (h*60 + m) % (24 * 60)

	if total < 0 {
		total += 24 * 60
	}

	return Clock{
		hour:   total / 60,
		minute: total % 60,
	}
}

// Add returns a new clock with m minutes added to the c clock.
func (c Clock) Add(m int) Clock {
	return New(c.hour, c.minute+m)
}

// Subtract returns a new clock with m minutes subtracted from the c clock.
func (c Clock) Subtract(m int) Clock {
	return c.Add(-m)
}

// String returns the string representation of the clock.
func (c Clock) String() string {
	return fmt.Sprintf("%02d:%02d", c.hour, c.minute)
}
