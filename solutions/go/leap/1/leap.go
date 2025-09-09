// Package leap provides a function for determining leap years.
package leap

// IsLeapYear returns whether or not the given year is a leap year.
func IsLeapYear(year int) bool {
	return year%400 == 0 || (year%4 == 0 && year%100 != 0)
}
