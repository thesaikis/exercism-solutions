class ArmstrongNumbers {

    boolean isArmstrongNumber(int numberToCheck) {
        int total = 0;
        int temp = numberToCheck;
        int n = (int) Math.log10(numberToCheck) + 1;

        while (temp > 0) {
            total += Math.pow(temp % 10, n);
            temp /= 10;
        }

        return total == numberToCheck;
    }

}
