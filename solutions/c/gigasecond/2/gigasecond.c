#include "gigasecond.h"

#define GIGASECOND 1000000000

void gigasecond(time_t before, char* after, size_t size) {
    before = before + GIGASECOND;
    strftime(after, size, "%Y-%m-%d %H:%M:%S", gmtime(&(before)));
}