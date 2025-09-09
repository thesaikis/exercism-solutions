import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Matrix {
    private final Set<MatrixCoordinate> saddlePoints = new HashSet<MatrixCoordinate>();

    Matrix(List<List<Integer>> values) {
        List<Integer> maxes = new ArrayList<Integer>();
        for (List<Integer> row : values)
            maxes.add(Collections.max(row));

        for (int row = 0; row < values.size(); row++) {
            for (int col = 0; col < values.get(row).size(); col++) {
                Integer candidate = values.get(row).get(col);

                if (candidate < maxes.get(row))
                    continue;

                boolean isMin = true;
                for (int i = 0; i < values.size(); i++) {
                    if (candidate > values.get(i).get(col)) {
                        isMin = false;
                        break;
                    }
                }

                if (isMin)
                    saddlePoints.add(new MatrixCoordinate(row + 1, col + 1));
            }
        }
    }

    Set<MatrixCoordinate> getSaddlePoints() {
        return saddlePoints;
    }
}
