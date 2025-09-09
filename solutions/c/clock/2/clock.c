#include "clock.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

clock_t clock_create(int hour, int minute) { 
    if (minute < 0) {
        hour -= (-(minute / 60) + 1);
        minute -= 60 * (minute / 60);
        minute = 60 + minute;
    }

    if (hour < 0) {
        hour += 24 * (-(hour / 24) + 1);
    }

    hour += minute / 60;
    minute %= 60;
    hour %= 24;

    clock_t clock;
    sprintf(clock.text, "%02d:%02d", hour, minute);

    return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {
    int hour;
    int minute;

    sscanf(clock.text, "%d:%d", &hour, &minute);

    clock_t new_clock = clock_create(hour, minute + minute_add);

    return new_clock;
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
    int hour;
    int minute;

    sscanf(clock.text, "%d:%d", &hour, &minute);

    clock_t new_clock = clock_create(hour, minute - minute_subtract);

    return new_clock;
}

bool clock_is_equal(clock_t a, clock_t b) {
    int hour_a;
    int minute_a;

    int hour_b;
    int minute_b;

    sscanf(a.text, "%d:%d", &hour_a, &minute_a);
    sscanf(b.text, "%d:%d", &hour_b, &minute_b);

    clock_t a_new = clock_create(hour_a, minute_a);
    clock_t b_new = clock_create(hour_b, minute_b);

    return strncmp(a_new.text, b_new.text, MAX_STR_LEN) == 0;
}