class DoublyLinkedList<T> {
    private Element<T> head;
    private Element<T> tail;

    void push(T value) {
        if (head == null) {
            head = new Element<T>(value, null, null);
            tail = head;
        } else {
            tail.next = new Element<T>(value, tail, null);
            tail = tail.next;
        }
    }

    T pop() {
        if (head == null)
            return null;

        T temp = tail.value;

        if (head == tail) {
            head = null;
            tail = null;
        } else {
            tail = tail.prev;
        }

        return temp;
    }

    void unshift(T value) {
        if (head == null) {
            head = new Element<T>(value, null, null);
            tail = head;
        } else {
            head.prev = new Element<T>(value, null, head);
            head = head.prev;
        }
    }

    T shift() {
        if (head == null)
            return null;

        T temp = head.value;

        if (head == tail) {
            head = null;
            tail = null;
        } else {
            head = head.next;
        }

        return temp;
    }

    private static final class Element<T> {
        private final T value;
        private Element<T> prev;
        private Element<T> next;

        Element(T value, Element<T> prev, Element<T> next) {
            this.value = value;
            this.prev = prev;
            this.next = next;
        }
    }
}
