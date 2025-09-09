// Package strain provides generic functions for filtering and discarding elements from slices.
package strain

type Keeper[T any] interface {
	Keep(filter func(T) bool) []T
}

type Ints []int
type Lists [][]int
type Strings []string

// Keep returns a new Ints slice containing only the integers
// for which the filter function returns true.
func (i Ints) Keep(filter func(int) bool) Ints {
	return keepGeneric(i, filter)
}

// Discard returns a new Ints slice containing only the integers
// for which the filter function returns false.
func (i Ints) Discard(filter func(int) bool) Ints {
	return discardGeneric(i, filter)
}

// Keep returns a new Lists slice containing only the integer slices
// for which the filter function returns true.
func (l Lists) Keep(filter func([]int) bool) Lists {
	return keepGeneric(l, filter)
}

// Keep returns a new Strings slice containing only the strings
// for which the filter function returns true.
func (s Strings) Keep(filter func(string) bool) Strings {
	return keepGeneric(s, filter)
}

// keepGeneric is a generic function that returns a new slice containing
// only the elements for which the filter function returns true.
func keepGeneric[T any](data []T, filter func(T) bool) []T {
	if data == nil {
		return nil
	}

	result := make([]T, 0)

	for _, item := range data {
		if filter(item) {
			result = append(result, item)
		}
	}

	return result
}

// discardGeneric is a generic function that returns a new slice containing
// only the elements for which the filter function returns false.
func discardGeneric[T any](data []T, filter func(T) bool) []T {
	return keepGeneric(data, func(item T) bool {
		return !filter(item)
	})
}
