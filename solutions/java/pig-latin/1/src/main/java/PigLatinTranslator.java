import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class PigLatinTranslator {

    private static final Set<Character> vowels = new HashSet<>(List.of('a', 'e', 'i', 'o', 'u'));

    public String translate(String text) {
        List<String> words = new ArrayList<>();

        for (String word : text.split(" ")) {
            if (vowels.contains(word.charAt(0)) || word.startsWith("xr") || word.startsWith("yt")) {
                words.add(word + "ay");
            } else {
                for (int i = 1; i < word.length(); i++) {
                    char let = word.charAt(i);

                    if (vowels.contains(let) || let == 'y') {
                        if (let == 'u' && word.charAt(i - 1) == 'q')
                            ++i;

                        words.add(word.substring(i) + word.substring(0, i) + "ay");
                        break;
                    }
                }
            }
        }

        return String.join(" ", words);
    }

}