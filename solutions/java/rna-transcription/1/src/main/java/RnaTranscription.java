import java.util.stream.Collectors;

class RnaTranscription {
    private static char customMap(char c) {
        switch (c) {
            case 'G':
                return 'C';
            case 'C':
                return 'G';
            case 'T':
                return 'A';
            case 'A':
                return 'U';
            default:
                return c;
        }
    }

    String transcribe(String dnaStrand) {
        return dnaStrand.chars().mapToObj(c -> customMap((char) c)).map(String::valueOf).collect(Collectors.joining());
    }

}
