package spiralmatrix

const (
	East = iota
	South
	West
	North
)

func SpiralMatrix(size int) [][]int {
	mat := make([][]int, size)
	for i := 0; i < size; i++ {
		mat[i] = make([]int, size)
	}

	top, right, bottom, left := -1, size, size, -1
	r, c := 0, 0
	dir := East

	for i := 1; i <= size*size; i++ {
		mat[r][c] = i

		switch dir {
		case East:
			c++
		case South:
			r++
		case West:
			c--
		case North:
			r--
		}

		if c == right {
			dir = South
			c--
			r++
			top++
		} else if r == bottom {
			dir = West
			r--
			c--
			right--
		} else if c == left {
			dir = North
			c++
			r--
			bottom--
		} else if r == top {
			dir = East
			r++
			c++
			left++
		}
	}

	return mat
}
