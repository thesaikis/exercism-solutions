package matrix

import (
	"errors"
	"strconv"
	"strings"
)

type Matrix [][]int

// New returns a new Matrix based off the given string.
func New(s string) (Matrix, error) {
	newMatrix := make(Matrix, 0)
	rowLength := -1

	for _, row := range strings.Split(s, "\n") {
		newRow := make([]int, 0)
		for _, num := range strings.Split(strings.TrimSpace(row), " ") {
			conv, err := strconv.Atoi(num)

			if err != nil {
				return nil, errors.New("invalid data in matrix")
			}

			newRow = append(newRow, conv)
		}

		if rowLength < 0 {
			rowLength = len(newRow)
		} else if len(newRow) != rowLength {
			return nil, errors.New("mismatched row lengths")
		}

		newMatrix = append(newMatrix, newRow)
	}

	return newMatrix, nil
}

// Cols returns the column representation of the given matrix.
func (m Matrix) Cols() [][]int {
	mCopy := make(Matrix, len(m[0]))
	for idx := range m {
		for jdx, num := range m[idx] {
			mCopy[jdx] = append(mCopy[jdx], num)
		}
	}
	return mCopy
}

// Rows returns the row representation of the given matrix.
func (m Matrix) Rows() [][]int {
	mCopy := make(Matrix, len(m))
	for idx := range m {
		mCopy[idx] = append(mCopy[idx], m[idx]...)
	}
	return mCopy
}

// Set modifies the value in the given matrix.
func (m Matrix) Set(row, col, val int) bool {
	if row < 0 || row >= len(m) || col < 0 || col >= len(m[0]) {
		return false
	}

	m[row][col] = val
	return true
}
