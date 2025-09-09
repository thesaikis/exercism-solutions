package flatten

// Flatten returns the flattened slice of the given (possibly nested) slice.
func Flatten(nested interface{}) []interface{} {
	flat := make([]interface{}, 0)

	switch data := nested.(type) {
	case []interface{}:
		for _, val := range data {
			flat = append(flat, Flatten(val)...)
		}
	case interface{}:
		flat = append(flat, data)
	}

	return flat
}
