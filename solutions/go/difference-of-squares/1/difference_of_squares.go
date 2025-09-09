// Package diffsquares provides functions for various calculations with squares and sums.
package diffsquares

// SquareOfSum returns the squared sum of integers 1 to n.
func SquareOfSum(n int) int {
	sum := n * (n + 1) / 2
	return sum * sum
}

// SumOfSquares returns the sum of integers 1 to n with each number squared.
func SumOfSquares(n int) int {
	return n * (n + 1) * (2*n + 1) / 6
}

// Difference returns the difference between the SquareOfSum and SumOfSquares for
// integers 1 to n.
func Difference(n int) int {
	return SquareOfSum(n) - SumOfSquares(n)
}
