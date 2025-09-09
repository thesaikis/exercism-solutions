import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Anagram {
    private String word;

    public Anagram(String word) {
        this.word = word;
    }

    public List<String> match(List<String> candidates) {
        List<String> result = new ArrayList<>();
        HashMap<Character, Integer> wordFreq = letterFrequencies(word);

        for (String cand : candidates) {
            if (!cand.equalsIgnoreCase(word) && wordFreq.equals(letterFrequencies(cand)))
                result.add(cand);
        }

        return result;
    }

    private HashMap<Character, Integer> letterFrequencies(String word) {
        HashMap<Character, Integer> result = new HashMap<>();

        for (char c : word.toCharArray()) {
            result.compute(Character.toLowerCase(c), (k, v) -> (v == null) ? 1 : v + 1);
        }

        return result;
    }
}