class BufferFullException(BufferError):
    """Exception raised when CircularBuffer is full.

    message: explanation of the error.

    """

    def __init__(self, message):
        self.message = message


class BufferEmptyException(BufferError):
    """Exception raised when CircularBuffer is empty.

    message: explanation of the error.

    """

    def __init__(self, message):
        self.message = message


class CircularBuffer:
    def __init__(self, capacity):
        self.__buffer = [0] * capacity
        self.capacity = capacity
        self.head, self.tail = 0, 0
        self.size = 0

    def read(self):
        if self.size == 0:
            raise BufferEmptyException("Circular buffer is empty")

        read_val = self.__buffer[self.head]
        self.head = (self.head + 1) % self.capacity
        self.size -= 1
        return read_val

    def write(self, data):
        if self.size == self.capacity:
            raise BufferFullException("Circular buffer is full")

        self.__buffer[self.tail] = data
        self.tail = (self.tail + 1) % self.capacity
        self.size += 1

    def overwrite(self, data):
        if self.size == self.capacity:
            self.read()
        self.write(data)

    def clear(self):
        self.size = 0
        self.head = self.tail
