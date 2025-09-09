import java.util.Arrays;
import java.util.List;

class ResistorColorDuo {
    private static final List<String> colors_ = Arrays.asList("black", "brown", "red", "orange", "yellow", "green",
            "blue", "violet", "grey", "white");

    int value(String[] colors) {
        return colors_.indexOf(colors[0]) * 10 + colors_.indexOf(colors[1]);
    }
}
