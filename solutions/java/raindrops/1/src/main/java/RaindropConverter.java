import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

class RaindropConverter {
    private static final Map<Integer, String> drops = new HashMap<>();

    static {
        drops.put(3, "Pling");
        drops.put(5, "Plang");
        drops.put(7, "Plong");
    }

    String convert(int number) {
        String result = drops.keySet().stream().filter(f -> number % f == 0).map(drops::get)
                .collect(Collectors.joining(""));
        return result.isEmpty() ? Integer.toString(number) : result;
    }

}
