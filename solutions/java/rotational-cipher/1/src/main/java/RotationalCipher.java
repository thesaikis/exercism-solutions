import java.util.stream.Collectors;

class RotationalCipher {
    private final int key;

    RotationalCipher(int shiftKey) {
        this.key = shiftKey;
    }

    String rotate(String data) {
        return data.chars().mapToObj((c) -> Character.toString(charRot(c, key))).collect(Collectors.joining());
    }

    private static int charRot(int c, int key) {
        if (!Character.isLetter(c))
            return (int) c;
        char base = Character.isUpperCase(c) ? 'A' : 'a';
        return (c - base + key) % 26 + base;
    }
}
