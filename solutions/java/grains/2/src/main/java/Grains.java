import java.math.BigInteger;

class Grains {
    private static final int MIN_BOARD_SIZE = 1;
    private static final int MAX_BOARD_SIZE = 64;

    BigInteger grainsOnSquare(final int square) {
        if (square < MIN_BOARD_SIZE || square > MAX_BOARD_SIZE)
            throw new IllegalArgumentException("square must be between 1 and 64");

        return BigInteger.valueOf(1).shiftLeft(square - 1);
    }

    BigInteger grainsOnBoard() {
        return BigInteger.valueOf(1).shiftLeft(MAX_BOARD_SIZE).subtract(BigInteger.ONE);
    }

}
