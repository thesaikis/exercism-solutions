import java.util.ArrayList;
import java.util.List;

class Flattener {

    <T> List<T> flatten(List<T> list) {
        List<T> flattenedArray = new ArrayList<T>();

        for (T item : list) {
            if (item instanceof List) {
                flattenedArray.addAll(flatten((List<T>) item));
            } else if (item instanceof Object) {
                flattenedArray.add(item);
            }
        }

        return flattenedArray;
    }

}