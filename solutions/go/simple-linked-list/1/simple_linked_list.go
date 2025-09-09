package linkedlist

import "errors"

type Node struct {
	val  int
	next *Node
}

type List struct {
	head *Node
	tail *Node
}

func New(elements []int) *List {
	newList := List{}

	if len(elements) == 0 {
		return &newList
	}

	newList.head = &Node{
		val: elements[0],
	}
	curNode := newList.head

	for i := 1; i < len(elements); i++ {
		curNode.next = &Node{
			val: elements[i],
		}
		curNode = curNode.next
	}
	newList.tail = curNode

	return &newList
}

func (l *List) Size() int {
	size := 0

	for node := l.head; node != nil; node = node.next {
		size++
	}

	return size
}

func (l *List) Push(element int) {
	newNode := &Node{
		val: element,
	}
	if l.head == nil {
		l.head = newNode
		l.tail = newNode
	} else {
		l.tail.next = newNode
		l.tail = l.tail.next
	}
}

func (l *List) Pop() (int, error) {
	if l.head == nil {
		return 0, errors.New("cannot pop from empty list")
	} else if l.tail == l.head {
		temp := l.head.val
		l.head = nil
		l.tail = nil
		return temp, nil
	}

	node := l.head
	for ; node.next != l.tail; node = node.next {}

	temp := node.next.val
	l.tail = node
	l.tail.next = nil
	return temp, nil
}

func (l *List) Array() []int {
	newArray := make([]int, 0)

	for curNode := l.head; curNode != nil; curNode = curNode.next {
		newArray = append(newArray, curNode.val)
	}

	return newArray
}

func (l *List) Reverse() *List {
	var prev, next *Node
	current := l.head
	l.tail = l.head

	for current != nil {
		next = current.next
		current.next = prev
		prev = current
		current = next
	}

	l.head = prev
	return l
}
