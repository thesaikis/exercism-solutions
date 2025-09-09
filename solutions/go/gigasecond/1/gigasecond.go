// Package gigasecond provides a function for adding a gigasecond.
package gigasecond

import "time"

// AddGigasecond returns the time one gigasecond after the given time.
func AddGigasecond(t time.Time) time.Time {
	return t.Add(time.Second * 1e9)
}
