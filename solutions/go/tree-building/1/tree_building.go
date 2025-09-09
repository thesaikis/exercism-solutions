package tree

import (
	"errors"
	"sort"
)

type Record struct {
	ID     int
	Parent int
}

type Node struct {
	ID       int
	Children []*Node
	Parent   int
}

// Build creates a tree given a list of records.
func Build(records []Record) (*Node, error) {
	if len(records) == 0 {
		return nil, nil
	}

	sort.Slice(records, func(i, j int) bool {
		return records[i].ID < records[j].ID
	})

	for i := 1; i < len(records); i++ {
		if records[i].ID != records[i-1].ID+1 {
			return nil, errors.New("non-continuous IDs detected")
		}
	}

	nodeById := make(map[int]*Node)

	for i := 0; i < len(records); i++ {
		if _, ok := nodeById[records[i].ID]; ok {
			return nil, errors.New("duplicate node")
		}
		nodeById[records[i].ID] = &Node{
			ID:     records[i].ID,
			Parent: records[i].Parent,
		}
	}

	rootNode, ok := nodeById[0]

	if !ok {
		return nil, errors.New("no root node given")
	} else if rootNode.Parent != 0 {
		return nil, errors.New("root node has parent")
	}

	for _, node := range nodeById {
		if node.ID == 0 {
			continue
		}

		if node.ID <= node.Parent {
			return nil, errors.New("invalid parent")
		}

		parentNode := nodeById[node.Parent]

		index := sort.Search(len(parentNode.Children), func(i int) bool {
			return parentNode.Children[i].ID > node.ID
		})

		parentNode.Children = append(parentNode.Children, nil)
		copy(parentNode.Children[index+1:], parentNode.Children[index:])
		parentNode.Children[index] = node
	}

	return rootNode, nil
}
