#include "meetup.h"

#include <string.h>
#include <time.h>

enum day { Sun, Mon, Tue, Wed, Thu, Fri, Sat };

static const __uint8_t in_month[12] = {31, 28, 31, 30, 31, 30,
                                       31, 31, 30, 31, 30, 31};

static enum day dayOfWeek(const char *week) {
    if (strcmp("Sunday", week) == 0) return Sun;
    if (strcmp("Monday", week) == 0) return Mon;
    if (strcmp("Tuesday", week) == 0) return Tue;
    if (strcmp("Wednesday", week) == 0) return Wed;
    if (strcmp("Thursday", week) == 0) return Thu;
    if (strcmp("Friday", week) == 0) return Fri;
    return Sat;
}

static int leap_year(int year) {
    return !((year % 400) && (year % 4 || !(year % 100)));
}

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week) {
    struct tm t = {.tm_year = year - 1900, .tm_mon = month - 1, .tm_mday = 1};
    mktime(&t);  // For tm_wday

    int day = 1 + dayOfWeek(day_of_week) - t.tm_wday;
    if (day < 1) day += 7;

    if (strcmp("first", week) == 0) return day;
    if (strcmp("second", week) == 0) return day + 7;
    if (strcmp("third", week) == 0) return day + 14;
    if (strcmp("fourth", week) == 0) return day + 21;
    if (strcmp("last", week) == 0)
        return day + 28 > (leap_year(year) > 0 &&
                                   t.tm_mon == 1  // Check if it's a leap year
                                                  // and the month is February
                               ? 29
                               : in_month[t.tm_mon])
                   ? day + 21
                   : day + 28;
    return day + 7 < 13 ? day + 14 : day + 7;  // teenth
}