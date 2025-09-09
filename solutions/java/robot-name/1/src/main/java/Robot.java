import java.util.Set;
import java.util.HashSet;
import java.util.Random;

class Robot {
    private String name;
    private static final Set<String> generated = new HashSet<>();
    private static final Random random = new Random();
    private static final String CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    private static final String NUMS = "0123456789";

    String getName() {
        if (this.name != null)
            return this.name;

        StringBuilder sb = new StringBuilder();

        while (true) {
            for (int i = 0; i < 2; i++) {
                sb.append(CHARS.charAt(random.nextInt(CHARS.length())));
            }
            for (int i = 0; i < 3; i++) {
                sb.append(NUMS.charAt(random.nextInt(NUMS.length())));
            }

            if (generated.contains(sb.toString())) {
                sb.setLength(0);
            } else {
                generated.add(sb.toString());
                name = sb.toString();
                return sb.toString();
            }
        }
    }

    void reset() {
        this.name = null;
    }

}