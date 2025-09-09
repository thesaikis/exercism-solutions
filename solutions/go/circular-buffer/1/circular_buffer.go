package circular

import "errors"

type Buffer struct {
	data     []byte
	size     int
	capacity int
	head     int
	tail     int
}

func NewBuffer(size int) *Buffer {
	return &Buffer{
		data:     make([]byte, size),
		capacity: size,
	}
}

func (b *Buffer) ReadByte() (byte, error) {
	if b.size == 0 {
		return 0, errors.New("cannot read from an empty buffer")
	}

	read := b.data[b.head]
	b.head = (b.head + 1) % b.capacity
	b.size--
	return read, nil
}

func (b *Buffer) WriteByte(c byte) error {
	if b.size == b.capacity {
		return errors.New("cannot write to a full buffer")
	}

	b.data[b.tail] = c
	b.tail = (b.tail + 1) % b.capacity
	b.size++
	return nil
}

func (b *Buffer) Overwrite(c byte) {
	if b.size == b.capacity {
		b.ReadByte()
	}
	b.WriteByte(c)
}

func (b *Buffer) Reset() {
	b.size = 0
	b.head = 0
	b.tail = 0
}
