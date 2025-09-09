import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;
import java.util.stream.Stream;

class DnDCharacter {
    private final Random random = new Random();
    private final int[] stats = Stream.generate(() -> ability(rollDice())).limit(6).mapToInt(Integer::intValue)
            .toArray();

    int ability(List<Integer> scores) {
        return scores.stream().sorted().skip(1).reduce(0, Integer::sum);
    }

    List<Integer> rollDice() {
        return random.ints(4, 1, 7).boxed().collect(Collectors.toList());
    }

    int modifier(int input) {
        return (int) Math.floor((input - 10) / 2.0);
    }

    int getStrength() {
        return stats[0];
    }

    int getDexterity() {
        return stats[1];
    }

    int getConstitution() {
        return stats[2];
    }

    int getIntelligence() {
        return stats[3];
    }

    int getWisdom() {
        return stats[4];
    }

    int getCharisma() {
        return stats[5];
    }

    int getHitpoints() {
        return 10 + modifier(getConstitution());
    }
}
