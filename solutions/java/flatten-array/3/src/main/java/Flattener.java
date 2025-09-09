import java.util.ArrayList;
import java.util.List;

class Flattener {

    List<Object> flatten(List<?> list) {
        List<Object> flattenedArray = new ArrayList<Object>();

        for (Object item : list) {
            if (item instanceof List<?> itemList) {
                flattenedArray.addAll(flatten(itemList));
            } else if (item != null) {
                flattenedArray.add(item);
            }
        }

        return flattenedArray;
    }

}