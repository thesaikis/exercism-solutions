import java.util.List;

class BinarySearch {
    private final List<Integer> items;

    BinarySearch(List<Integer> items) {
        this.items = items;
    }

    int indexOf(int item) throws ValueNotFoundException {
        int left = 0, right = items.size() - 1;

        while (left <= right) {
            int mid = (right + left) / 2;
            int val = items.get(mid);

            if (item == val) {
                return mid;
            } else if (item > val) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        throw new ValueNotFoundException("Value not in array");
    }
}
