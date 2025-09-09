import java.util.ArrayList;
import java.util.List;

class Flattener {

    List<Object> flatten(List<?> list) {
        List<Object> flattenedArray = new ArrayList<Object>();

        for (Object item : list) {
            if (item instanceof List) {
                flattenedArray.addAll(flatten((List<?>) item));
            } else if (item instanceof Object) {
                flattenedArray.add(item);
            }
        }

        return flattenedArray;
    }

}