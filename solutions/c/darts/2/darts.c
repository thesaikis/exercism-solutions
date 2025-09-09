#include <inttypes.h>
#include <math.h>

#include "darts.h"

uint8_t score(coordinate_t landing_position) {
    float dist_to_radius = hypot(landing_position.x, landing_position.y);

    if (dist_to_radius <= 1) return 10;
    else if (dist_to_radius <= 5) return 5;
    else if (dist_to_radius <= 10) return 1;
    else return 0;
}