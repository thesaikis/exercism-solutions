#include "resistor_color_trio.h"

#include <math.h>

resistor_value_t color_code(resistor_band_t bands[]) {
    uint64_t value = (10 * bands[0] + bands[1]) * pow(10, bands[2]);
    unit_t unit = OHMS;

    while (value >= 1000 && unit <= GIGAOHMS) {
        value /= 1000;
        unit++;
    }
    
    return (resistor_value_t) { value, unit };
}