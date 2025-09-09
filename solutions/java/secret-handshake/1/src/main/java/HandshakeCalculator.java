import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

class HandshakeCalculator {

    List<Signal> calculateHandshake(int number) {
        List<Signal> actions = Arrays.stream(Signal.values()).filter((s) -> (number & (1 << s.ordinal())) > 0)
                .collect(Collectors.toList());
        if ((number & (1 << 4)) > 0)
            Collections.reverse(actions);
        return actions;
    }

}
