package pascal

// Triangle returns each row of pascal's triangle.
func Triangle(n int) [][]int {
	triangle := make([][]int, n)
	triangle[0] = []int{1}

	for i := 1; i < n; i++ {
		newRow := []int{}
		for j := 0; j <= len(triangle[i-1]); j++ {
			newRow = append(newRow, pascalIndex(triangle[i-1], j)+pascalIndex(triangle[i-1], j-1))
		}
		triangle[i] = newRow
	}

	return triangle
}

// pascalIndex returns 0 if the index is out of range, otherwise the number at the index.
func pascalIndex(ints []int, idx int) int {
	if idx < 0 || idx >= len(ints) {
		return 0
	}
	return ints[idx]
}
