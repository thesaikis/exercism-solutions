public class PopCount {
    public int eggCount(int number) {
        return Integer.toBinaryString(number).replaceAll("[^1]", "").length();
    }
}
