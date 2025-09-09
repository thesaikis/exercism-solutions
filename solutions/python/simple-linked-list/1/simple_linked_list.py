class Node:
    def __init__(self, value):
        self._value = value
        self._next = None

    def value(self):
        return self._value

    def next(self):
        return self._next


class LinkedList:
    def __init__(self, values=[]):
        self._head = Node(values[0]) if values else None
        for i in range(1, len(values)):
            self.push(values[i])

    def __len__(self):
        node = self._head
        length = 0

        while node is not None:
            node = node.next()
            length += 1

        return length

    def head(self):
        if len(self) == 0:
            raise EmptyListException("The list is empty.")
        return self._head

    def push(self, value):
        new_node = Node(value)
        new_node._next = self._head
        self._head = new_node

    def pop(self):
        to_return = self.head()
        self._head = self._head.next()
        return to_return.value()

    def __iter__(self):
        self._iter_next = self._head
        return self

    def __next__(self):
        if self._iter_next is None:
            raise StopIteration
        to_return = self._iter_next.value()
        self._iter_next = self._iter_next.next()
        return to_return

    def reversed(self):
        return reversed(list(self))


class EmptyListException(Exception):
    def __init__(self, message):
        self.message = message
