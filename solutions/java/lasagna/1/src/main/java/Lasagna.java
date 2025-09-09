public class Lasagna {
    public int expectedMinutesInOven() {
        return 40;
    }

    public int remainingMinutesInOven(int curMinutes) {
        return expectedMinutesInOven() - curMinutes; 
    }

    public int preparationTimeInMinutes(int layers) {
        return layers * 2;
    }

    public int totalTimeInMinutes(int layers, int curMinutes) {
        return preparationTimeInMinutes(layers) + curMinutes;
    }
}
