public class ElonsToyCar {
    int distanceDriven;
    int battery = 100;

    public static ElonsToyCar buy() {
        return new ElonsToyCar();
    }

    public String distanceDisplay() {
        return String.format("Driven %d meters", distanceDriven);
    }

    public String batteryDisplay() {
        if (battery == 0) {
            return "Battery empty";
        }

        return String.format("Battery at %d%%", battery);
    }

    public void drive() {
        if (battery >= 1) {
            distanceDriven += 20;
            battery--;
        }
    }
}
