import java.util.HashSet;

public class PangramChecker {

    public boolean isPangram(String input) {
        return new HashSet<Integer>(input.toLowerCase().chars().filter(c -> Character.isAlphabetic((char) c)).boxed().toList()).size() == 26;
    }

}
