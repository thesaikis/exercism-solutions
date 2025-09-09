public class ExperimentalRemoteControlCar implements RemoteControlCar {
    private int distanceTravelled;
    private static final int speed = 20;

    public void drive() {
        distanceTravelled += speed;
    }

    public int getDistanceTravelled() {
        return distanceTravelled;
    }
}
