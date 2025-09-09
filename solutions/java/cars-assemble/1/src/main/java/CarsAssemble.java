public class CarsAssemble {
    private static int CARS_PER_HOUR = 221;

    public double productionRatePerHour(int speed) {
        double successRate = 1.0;

        if (speed == 10) {
            successRate = 0.77;
        } else if (speed == 9) {
            successRate = 0.8;
        } else if (speed >= 5) {
            successRate = 0.9;
        }

        return speed * CARS_PER_HOUR * successRate;
    }

    public int workingItemsPerMinute(int speed) {
        return (int) (productionRatePerHour(speed) / 60);
    }
}
