import java.util.Arrays;

class Acronym {

    private String myAcronym;

    Acronym(String phrase) {
        this.myAcronym = Arrays.stream(phrase.split(" |-|_"))
                .filter(word -> !word.isEmpty())
                .map(word -> Character.toUpperCase(word.charAt(0)))
                .collect(StringBuilder::new, StringBuilder::append, StringBuilder::append)
                .toString();
    }

    String get() {
        return this.myAcronym;
    }

}
