import java.util.regex.*;

class SqueakyClean {
    static String clean(String identifier) {
        String almostClean = identifier.replace(' ', '_')
                .replaceAll("[\\p{Cntrl}]", "CTRL")
                .replaceAll("[^\\p{L}_-]", "")
                .replaceAll("[\u03b1-\u03c9]", "");

        Matcher m = Pattern.compile("-([\\p{L}])").matcher(almostClean);
        if (m.find()) {
            return m.replaceAll(m.group(1).toUpperCase());
        }
        return almostClean;
    }
}
