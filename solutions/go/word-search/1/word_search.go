package wordsearch

import (
	"errors"
	"strings"
)

func reverseString(str string) string {
	b := []rune(str)
	for i, j := 0, len(b)-1; i < j; i, j = i+1, j-1 {
		b[i], b[j] = b[j], b[i]
	}
	return string(b)
}

func searchLeftToRight(word string, rows []string) [2][2]int {
	for rowIdx, row := range rows {
		idx := strings.Index(row, word)

		if idx != -1 {
			return [2][2]int{{idx, rowIdx}, {idx + len(word) - 1, rowIdx}}
		}
	}

	return [2][2]int{{-1, -1}, {-1, -1}}
}

func searchRightToLeft(word string, rows []string) [2][2]int {
	for rowIdx, row := range rows {
		idx := strings.Index(row, word)

		if idx != -1 {
			return [2][2]int{{len(row) - idx - 1, rowIdx}, {len(row) - idx - len(word), rowIdx}}
		}
	}

	return [2][2]int{{-1, -1}, {-1, -1}}
}

func searchTopToBottom(word string, columns []string) [2][2]int {
	for colIdx, col := range columns {
		idx := strings.Index(col, word)

		if idx != -1 {
			return [2][2]int{{colIdx, idx}, {colIdx, idx + len(word) - 1}}
		}
	}

	return [2][2]int{{-1, -1}, {-1, -1}}
}

func searchBottomToTop(word string, columns []string) [2][2]int {
	for colIdx, col := range columns {
		idx := strings.Index(col, word)

		if idx != -1 {
			return [2][2]int{{colIdx, len(col) - idx - 1}, {colIdx, len(col) - idx - len(word)}}
		}
	}

	return [2][2]int{{-1, -1}, {-1, -1}}
}

func searchDiagonal(word string, puzzle []string, startRow int, startCol int) [2][2]int {
	wordLength := len(word)
	numRows := len(puzzle)
	numCols := len(puzzle[0])
	directions := [][2]int{{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}

	for _, direction := range directions {
		row, col := startRow, startCol
		match := true
		for i := 0; i < wordLength; i++ {
			newRow, newCol := row+i*direction[0], col+i*direction[1]
			if newRow < 0 || newRow >= numRows || newCol < 0 || newCol >= numCols || puzzle[newRow][newCol] != word[i] {
				match = false
				break
			}
		}
		if match {
			endRow, endCol := row+(wordLength-1)*direction[0], col+(wordLength-1)*direction[1]
			return [2][2]int{{startCol, startRow}, {endCol, endRow}}
		}
	}
	return [2][2]int{{-1, -1}, {-1, -1}}
}

func Solve(words []string, puzzle []string) (map[string][2][2]int, error) {
	res := make(map[string][2][2]int)
	reversedRows := make([]string, 0)
	topToBottomRows := make([]string, 0)
	bottomToTopRows := make([]string, 0)

	for _, row := range puzzle {
		reversedRows = append(reversedRows, reverseString(row))
	}

	for c := 0; c < len(puzzle[0]); c++ {
		var sb strings.Builder
		for r := 0; r < len(puzzle); r++ {
			sb.WriteByte(puzzle[r][c])
		}
		topToBottomRows = append(topToBottomRows, sb.String())
		bottomToTopRows = append(bottomToTopRows, reverseString(sb.String()))
	}

	for _, word := range words {
		res[word] = searchLeftToRight(word, puzzle)
		if res[word][0][0] == -1 {
			res[word] = searchRightToLeft(word, reversedRows)
		}
		if res[word][0][0] == -1 {
			res[word] = searchTopToBottom(word, topToBottomRows)
		}
		if res[word][0][0] == -1 {
			res[word] = searchBottomToTop(word, bottomToTopRows)
		}
		if res[word][0][0] == -1 {
			for r := 0; r < len(puzzle); r++ {
				for c := 0; c < len(puzzle[0]); c++ {
					res[word] = searchDiagonal(word, puzzle, r, c)
					if res[word][0][0] != -1 {
						break
					}
				}
				if res[word][0][0] != -1 {
					break
				}
			}
		}
	}

	for word, coords := range res {
		if coords[0][0] == -1 {
			return res, errors.New(word + " was not found.")
		}
	}

	return res, nil
}
