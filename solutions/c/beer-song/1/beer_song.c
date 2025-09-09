#include "beer_song.h"

#include <stdio.h>
#include <string.h>

static const char* basic_verse[] = {
    "%d bottles of beer on the wall, %d bottles of beer.",
    "Take one down and pass it around, %d bottle%s of beer on the wall."};

static const char* one_bottle_verse[] = {
    "1 bottle of beer on the wall, 1 bottle of beer.",
    "Take it down and pass it around, no more bottles of beer on the wall."};

static const char* special_verse[] = {
    "No more bottles of beer on the wall, no more bottles of beer.",
    "Go to the store and buy some more, 99 bottles of beer on the wall."};

static void verse(uint8_t bottles, char** dest) {
    if (bottles == 0) {
        strcpy(*dest, special_verse[0]);
        strcpy(*(dest + 1), special_verse[1]);
        return;
    } else if (bottles == 1) {
        strcpy(*dest, one_bottle_verse[0]);
        strcpy(*(dest + 1), one_bottle_verse[1]);
        return;
    }

    sprintf(*dest, basic_verse[0], bottles, bottles);
    sprintf(*(dest + 1), basic_verse[1], bottles - 1,
            (bottles - 1) > 1 ? "s" : "");
}

void recite(uint8_t start_bottles, uint8_t take_down, char** song) {
    for (int i = 0; i < 3 * take_down - 1; i += 3) {
        verse(start_bottles - (i / 3), &song[i]);
    }
}