package kindergarten

import (
	"errors"
	"sort"
	"strings"
)

type Garden struct {
	rows     []string
	children []string
}

// NewGarden returns new garden if the given diagram and children are valid.
func NewGarden(diagram string, children []string) (*Garden, error) {
	gardenRows := strings.Split(diagram, "\n")

	// The split diagram will have three parts: ["\n", row1, row2]
	// Check if number of rows is valid, rows are same length and not odd.
	if len(gardenRows) != 3 || len(gardenRows[1]) != len(gardenRows[2]) || len(gardenRows[1])%2 != 0 || len(gardenRows[2])%2 != 0 {
		return nil, errors.New("invalid diagram")
	}

	childrenCopy := append([]string(nil), children...)
	sort.Strings(childrenCopy)

	// Check for any duplicate names.
	for i := 0; i < len(childrenCopy)-1; i++ {
		if childrenCopy[i] == childrenCopy[i+1] {
			return nil, errors.New("duplicate child name")
		}
	}

	// Check to see if all plants are valid.
	for _, row := range gardenRows[1:] {
		for _, char := range row {
			if char != 'G' && char != 'C' && char != 'R' && char != 'V' {
				return nil, errors.New("invalid plant")
			}
		}
	}

	return &Garden{
		rows:     gardenRows[1:],
		children: childrenCopy,
	}, nil
}

// Plants returns all the plants for the given child, if valid.
func (g *Garden) Plants(child string) ([]string, bool) {
	childPos := sort.SearchStrings(g.children, child)

	if childPos == len(g.children) || g.children[childPos] != child {
		return nil, false
	}

	childPlantsChars := []byte{g.rows[0][childPos*2], g.rows[0][childPos*2+1], g.rows[1][childPos*2], g.rows[1][childPos*2+1]}
	childPlants := []string{}

	for _, char := range childPlantsChars {
		switch char {
		case 'G':
			childPlants = append(childPlants, "grass")
		case 'C':
			childPlants = append(childPlants, "clover")
		case 'R':
			childPlants = append(childPlants, "radishes")
		case 'V':
			childPlants = append(childPlants, "violets")
		}
	}

	return childPlants, true
}
