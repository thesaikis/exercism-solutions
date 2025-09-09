// Package chessboard provides types for defining a chessboard and functions for counting spaces on it.
package chessboard

// A File stores if a square is occupied by a piece.
type File []bool

// A Chessboard contains a map of eight Files, accessed with keys from "A" to "H".
type Chessboard map[string]File

// CountInFile returns how many squares are occupied in the chessboard,
// within the given file.
func CountInFile(cb Chessboard, file string) int {
	boardFile, exists := cb[file]

	if !exists {
		return 0
	}

	var count int

	for _, v := range boardFile {
		if v {
			count++
		}
	}

	return count
}

// CountInRank returns how many squares are occupied in the chessboard,
// within the given rank.
func CountInRank(cb Chessboard, rank int) int {
	if rank < 1 || rank > 8 {
		return 0
	}

	var count int

	for _, file := range cb {
		if file[rank-1] {
			count++
		}
	}

	return count
}

// CountAll should count how many squares are present in the chessboard.
func CountAll(cb Chessboard) int {
	var count int

	for _, v := range cb {
		count += len(v)
	}

	return count
}

// CountOccupied returns how many squares are occupied in the chessboard.
func CountOccupied(cb Chessboard) int {
	var count int

	for let := range cb {
		count += CountInFile(cb, let)
	}

	return count
}
