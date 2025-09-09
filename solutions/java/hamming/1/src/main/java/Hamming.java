import java.util.stream.IntStream;

public class Hamming {
    private final String left;
    private final String right;

    public Hamming(String leftStrand, String rightStrand) {
        if (leftStrand.length() != rightStrand.length()) {
            if (rightStrand.isEmpty())
                throw new IllegalArgumentException("right strand must not be empty.");
            else if (leftStrand.isEmpty())
                throw new IllegalArgumentException("left strand must not be empty.");
            throw new IllegalArgumentException("leftStrand and rightStrand must be of equal length.");
        }

        this.left = leftStrand;
        this.right = rightStrand;
    }

    public int getHammingDistance() {
        return (int) IntStream.range(0, left.length()).filter(i -> left.charAt(i) != right.charAt(i)).count();
    }
}
