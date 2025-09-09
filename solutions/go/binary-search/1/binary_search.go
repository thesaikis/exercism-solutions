package binarysearch

import "sort"

// SearchInts returns the index of the key in the list, -1 if it doesn't exist.
func SearchInts(list []int, key int) int {
	sort.Ints(list)

	left, right := 0, len(list)-1

	for left <= right {
		mid := (right + left) / 2

		if list[mid] > key {
			right = mid - 1
		} else if list[mid] < key {
			left = mid + 1
		} else {
			return mid
		}
	}

	return -1
}
