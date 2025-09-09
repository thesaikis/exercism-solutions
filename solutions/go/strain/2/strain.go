// Package strain provides generic functions for filtering and discarding elements from slices.
package strain

// keepGeneric is a generic function that returns a new slice containing
// only the elements for which the filter function returns true.
func Keep[T any](data []T, filter func(T) bool) []T {
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
func Discard[T any](data []T, filter func(T) bool) []T {
	return Keep(data, func(item T) bool {
		return !filter(item)
	})
}
