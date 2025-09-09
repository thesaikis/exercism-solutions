class Scrabble {
    private final String word;

    Scrabble(String word) {
        this.word = word;
    }

    int getScore() {
        return word.toLowerCase().chars().map(Scrabble::scoreChar).reduce(0, Integer::sum);
    }

    private static int scoreChar(int c) {
        switch (c) {
            case 'q': case 'z': return 10;
            case 'j': case 'x': return 8;
            case 'k': return 5;
            case 'f': case 'h': case 'v': case 'w': case 'y': return 4;
            case 'b': case 'c': case 'm': case 'p': return 3;
            case 'd': case 'g': return 2;
            default: return 1;
        }
    }
}
