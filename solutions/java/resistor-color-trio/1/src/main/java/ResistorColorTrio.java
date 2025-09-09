import java.util.Arrays;
import java.util.List;

class ResistorColorTrio {

    static private List<String> colorBands = Arrays.asList("black", "brown", "red", "orange", "yellow", "green", "blue",
            "violet", "grey", "white");

    String label(String[] colors) {
        long resistance = colorBands.indexOf(colors[0]) * 10 + colorBands.indexOf(colors[1]);
        resistance *= (int) Math.pow(10, colorBands.indexOf(colors[2]));

        if (resistance >= 1000000000) {
            return String.format("%d gigaohms", resistance / 1000000000);
        } else if (resistance >= 1000000) {
            return String.format("%d megaohms", resistance / 1000000);
        } else if (resistance >= 1000) {
            return String.format("%d kiloohms", resistance / 1000);
        }

        System.out.println(resistance);

        return String.format("%d ohms", resistance);
    }
}
