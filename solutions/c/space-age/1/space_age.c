#include "space_age.h"

#define SECONDS_IN_YEAR (365 * 24 * 60 * 60)

const float orbital_periods[] = { 0.2408467, 0.61519726, 1, 1.8808158, 11.862615, 29.447498, 84.016846, 164.79132 };

float age(planet_t planet, int64_t seconds) {
    if (planet >= PLANET_COUNT) return -1;

    return seconds / SECONDS_IN_YEAR / orbital_periods[planet];
}