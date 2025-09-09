package listops

// IntList is an abstraction of a list of integers which we can define methods on
type IntList []int

// Foldl reduces each item of the given IntList into the accumulator, from the left.
func (s IntList) Foldl(fn func(int, int) int, initial int) int {
	for _, num := range s {
		initial = fn(initial, num)
	}

	return initial
}

// Foldr reduces each item of the given IntList into the accumulator, from the right.
func (s IntList) Foldr(fn func(int, int) int, initial int) int {
	for i := len(s) - 1; i >= 0; i-- {
		initial = fn(s[i], initial)
	}

	return initial
}

// Filter returns all items for which the given function evaluates to true.
func (s IntList) Filter(fn func(int) bool) IntList {
	newIntList := make(IntList, 0)

	for _, num := range s {
		if fn(num) {
			newIntList = append(newIntList, num)
		}
	}

	return newIntList
}

// Length returns the length of the given list.
func (s IntList) Length() int {
	return len(s)
}

// Map returns the list after applying the given function to each value.
func (s IntList) Map(fn func(int) int) IntList {
	for i := 0; i < len(s); i++ {
		s[i] = fn(s[i])
	}

	return s
}

// Reverse returns the reversed list.
func (s IntList) Reverse() IntList {
	newIntList := make(IntList, 0)

	for i := len(s) - 1; i >= 0; i-- {
		newIntList = append(newIntList, s[i])
	}

	return newIntList
}

// Append returns the two lists appended.
func (s IntList) Append(lst IntList) IntList {
	return append(s, lst...)
}

// Concat returns all lists concatenated together.
func (s IntList) Concat(lists []IntList) IntList {
	for _, list := range lists {
		s = append(s, list...)
	}

	return s
}
