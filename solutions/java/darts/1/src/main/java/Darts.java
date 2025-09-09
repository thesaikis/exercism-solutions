class Darts {
    int score(double xOfDart, double yOfDart) {
        double distance = Math.hypot(xOfDart, yOfDart);

        if (distance > 10) return 0;
        if (distance > 5)  return 1;
        if (distance > 1)  return 5;
        return 10;
    }
}
