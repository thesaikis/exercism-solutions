#include "resistor_color_trio.h"

#include <stdio.h>
#include <inttypes.h>
#include <math.h>

resistor_value_t color_code(resistor_band_t bands[]) {
    uint32_t value = (10 * bands[0] + bands[1]) * pow(10, bands[2]);
    unit_t unit = OHMS;

    if (value >= 1000) {
        value /= 1000;
        unit = KILOOHMS;
    }

    return (resistor_value_t) { value, unit };
}