import java.time.*;

public class Gigasecond {
    private LocalDateTime myTime;
    private final static int GIGASECOND = 1000000000;

    public Gigasecond(LocalDate moment) {
        myTime = LocalDateTime.of(moment, LocalTime.of(0, 0, 0)).plusSeconds(GIGASECOND);
    }

    public Gigasecond(LocalDateTime moment) {
        myTime = moment.plusSeconds(GIGASECOND);
    }

    public LocalDateTime getDateTime() {
        return myTime;
    }
}
