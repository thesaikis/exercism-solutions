package meetup

import "time"

type WeekSchedule int

const (
	First WeekSchedule = iota
	Second
	Third
	Fourth
	Teenth
	Last
)

// Day finds the First, Second, Third, Fourth, Teenth, or Last day of the month for the given Weekday.
func Day(wSched WeekSchedule, wDay time.Weekday, month time.Month, year int) int {
	var starterDay time.Time
	var daysToAdd int

	if wSched == Last {
		starterDay = time.Date(year, month+1, 0, 0, 0, 0, 0, time.UTC)
		daysToAdd = -((int(starterDay.Weekday()) - int(wDay) + 7) % 7)
	} else if wSched == Teenth {
		starterDay = time.Date(year, month, 13, 0, 0, 0, 0, time.UTC)
		daysToAdd = ((int(wDay) - int(starterDay.Weekday()) + 7) % 7)
	} else {
		starterDay = time.Date(year, month, 1, 0, 0, 0, 0, time.UTC)
		daysToAdd = ((int(wDay) - int(starterDay.Weekday()) + 7) % 7) + 7*int(wSched)
	}

	desiredDay := starterDay.AddDate(0, 0, daysToAdd)

	return desiredDay.Day()
}
