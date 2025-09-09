import java.util.HashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class WordCount {
    public Map<String, Integer> phrase(String input) {
        Map<String, Integer> freqs = new HashMap<>();

        Matcher mat = Pattern.compile("\\w+'\\w+|\\w+").matcher(input);

        while (mat.find())
            freqs.compute(mat.group().toLowerCase(), (k, v) -> (v == null) ? 1 : v + 1);

        return freqs;
    }
}
