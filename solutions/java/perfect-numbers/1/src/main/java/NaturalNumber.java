class NaturalNumber {

    private Classification classification;

    NaturalNumber(int number) {
        if (number <= 0) {
            throw new IllegalArgumentException("You must supply a natural number (positive integer)");
        }

        int sum = 0;

        for (int i = 1; i <= Math.sqrt(number); i++) {
            if (number % i == 0) {
                sum += i;
                if (i != number / i)
                    sum += number / i;
            }
        }

        sum -= number;

        if (sum == number) {
            this.classification = Classification.PERFECT;
        } else if (sum > number) {
            this.classification = Classification.ABUNDANT;
        } else {
            this.classification = Classification.DEFICIENT;
        }
    }

    Classification getClassification() {
        return this.classification;
    }
}
