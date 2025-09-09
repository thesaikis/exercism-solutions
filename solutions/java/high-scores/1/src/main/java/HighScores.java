import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class HighScores {

    private List<Integer> myScores;

    public HighScores(List<Integer> highScores) {
        this.myScores = new ArrayList<>(highScores);
    }

    List<Integer> scores() {
        return this.myScores;
    }

    Integer latest() {
        return this.myScores.getLast();
    }

    Integer personalBest() {
        return Collections.max(this.myScores);
    }

    List<Integer> personalTopThree() {
        return this.myScores.stream().sorted(Comparator.reverseOrder()).limit(3).toList();
    }

}
