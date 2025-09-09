// Package twofer provides a function that generates a message for sharing a cookie.
package twofer

// ShareWith returns a string for giving a cookie to another person,
// given their name. Is the name is the empty string, it defaults to
// a generic message.
func ShareWith(name string) string {
	if name == "" {
		return "One for you, one for me."
	}
	return "One for " + name + ", one for me."
}
