package linkedlist

import "errors"

type List struct {
	head *Node
	tail *Node
}

type Node struct {
	Value interface{}
	left  *Node
	right *Node
}

// NewList returns a new List with the given elements.
func NewList(elements ...interface{}) *List {
	if len(elements) == 0 {
		return &List{}
	}

	root := &Node{
		Value: elements[0],
	}

	list := List{
		head: root,
	}

	for i := 1; i < len(elements); i++ {
		newNode := Node{
			Value: elements[i],
			left:  root,
		}
		root.right = &newNode
		root = &newNode
	}

	list.tail = root
	return &list
}

// Next returns the node after n.
func (n *Node) Next() *Node {
	return n.right
}

// Prev returns the node before n.
func (n *Node) Prev() *Node {
	return n.left
}

// Unshift inserts a new value at the beginning of the list.
func (l *List) Unshift(v interface{}) {
	newNode := Node{
		Value: v,
		right: l.head,
	}

	if l.head != nil {
		l.head.left = &newNode
	} else {
		l.tail = &newNode
	}

	l.head = &newNode
}

// Push appends a value to the list.
func (l *List) Push(v interface{}) {
	newNode := Node{
		Value: v,
		left:  l.tail,
	}

	if l.tail != nil {
		l.tail.right = &newNode
	} else {
		l.head = &newNode
	}

	l.tail = &newNode
}

// Shift removes the first value from the list.
func (l *List) Shift() (interface{}, error) {
	if l.head == nil {
		return nil, errors.New("cannot shift an empty list")
	}

	temp := l.head.Value
	if l.head == l.tail {
		l.head = nil
		l.tail = nil
		return temp, nil
	}

	l.head = l.head.right
	l.head.left = nil
	return temp, nil
}

// Pop removes the last value from the list.
func (l *List) Pop() (interface{}, error) {
	if l.head == nil {
		return nil, errors.New("cannot pop from empty list")
	}

	temp := l.tail.Value
	if l.head == l.tail {
		l.head = nil
		l.tail = nil
		return temp, nil
	}

	l.tail = l.tail.left
	l.tail.right = nil
	return temp, nil
}

// Reverse reverses the list.
func (l *List) Reverse() {
	cur, prev := l.head, (*Node)(nil)

	for cur != nil {
		next := cur.right
		cur.right = prev
		cur.left = next
		prev = cur
		cur = next
	}

	l.head, l.tail = l.tail, l.head
}

// First returns the head of the list.
func (l *List) First() *Node {
	return l.head
}

// Last returns the tail of the list.
func (l *List) Last() *Node {
	return l.tail
}
