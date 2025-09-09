import java.util.Arrays;
import java.util.stream.IntStream;

class Matrix {
    String matrix;

    Matrix(String matrixAsString) {
        this.matrix = matrixAsString;
    }

    int[] getRow(int rowNumber) {
        return Arrays.stream(matrix.split("\n")[rowNumber - 1].split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    int[] getColumn(int columnNumber) {
        String[] rows = matrix.split("\n");
        return IntStream.range(0, rows.length).map((i) -> Integer.parseInt(rows[i].split(" ")[columnNumber - 1])).toArray();
    }
}
