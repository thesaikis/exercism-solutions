class Node:
    def __init__(self, value, succeeding=None, previous=None):
        self.value = value
        self.prev = previous
        self.next = succeeding


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.len = 0

    def push(self, value):
        new_node = Node(value, previous=self.tail)

        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

        self.len += 1

    def unshift(self, value):
        new_node = Node(value, succeeding=self.head)

        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.head.prev = new_node
            self.head = new_node

        self.len += 1

    def pop(self):
        self._check_empty()

        next_tail = self.tail.prev
        to_return = self.tail.value
        self.tail = next_tail

        if self.tail is None:
            self.head = None

        self.len -= 1
        return to_return

    def shift(self):
        self._check_empty()

        next_head = self.head.next
        to_return = self.head.value
        self.head = next_head

        if self.head is None:
            self.tail = None

        self.len -= 1
        return to_return

    def delete(self, value):
        if self.head and self.head.value == value:
            self.shift()
            return
        if self.tail and self.tail.value == value:
            self.pop()
            return

        node = self.head

        while node and node.next:
            if node.value == value:
                node.prev.next = node.next
                node.next.prev = node.prev
                self.len -= 1
                return

            node = node.next

        raise ValueError("Value not found")

    def _check_empty(self):
        if self.len == 0:
            raise IndexError("List is empty")

    def __len__(self):
        return self.len
