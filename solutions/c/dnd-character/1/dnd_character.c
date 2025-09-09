#include "dnd_character.h"

#include <math.h>
#include <stdlib.h>

int ability(void) {
    int min = DIE_FACES + 1;
    int sum = 0;

    for (int i = 0; i < ABILITY_ROLLS; i++) {
        int roll = rand() % DIE_FACES + 1;
        int min = roll < min ? roll : min;
        sum += roll;
    }

    return sum - min;
}

int modifier(int score) { return floor((score - 10) / 2.0); }

dnd_character_t make_dnd_character(void) {
    int constitution = ability();

    return (dnd_character_t){.charisma = ability(),
                             .dexterity = ability(),
                             .intelligence = ability(),
                             .strength = ability(),
                             .wisdom = ability(),
                             .constitution = constitution,
                             .hitpoints = modifier(constitution) + 10};
}