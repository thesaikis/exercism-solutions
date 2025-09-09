#include "two_bucket.h"

#include <stdio.h>

static bucket_liters_t gcd(bucket_liters_t a, bucket_liters_t b) {
    while (b != 0) {
        bucket_liters_t temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

bucket_result_t measure(bucket_liters_t bucket_1_size,
                        bucket_liters_t bucket_2_size,
                        bucket_liters_t goal_volume, bucket_id_t start_bucket) {
    bucket_result_t result = {.possible = true, .move_count = 0};

    if (goal_volume % gcd(bucket_1_size, bucket_2_size) != 0 ||
        (goal_volume > bucket_1_size && goal_volume > bucket_2_size)) {
        result.possible = false;
        return result;
    }

    bucket_liters_t main_bucket = 0;
    bucket_liters_t main_capac =
        start_bucket == BUCKET_ID_1 ? bucket_1_size : bucket_2_size;
    bucket_liters_t side_bucket = 0;
    bucket_liters_t side_capac =
        start_bucket == BUCKET_ID_1 ? bucket_2_size : bucket_1_size;

    while (main_bucket != goal_volume && side_bucket != goal_volume) {
        if (main_bucket == 0) {
            main_bucket = main_capac;
        } else if (side_capac == goal_volume) {
            side_bucket = side_capac;
        } else if (side_bucket == side_capac) {
            side_bucket = 0;
        } else {
            bucket_liters_t to_fill = side_capac - side_bucket;
            if (main_bucket < to_fill) {
                side_bucket += main_bucket;
                main_bucket = 0;
            } else {
                side_bucket += to_fill;
                main_bucket -= to_fill;
            }
        }

        result.move_count++;
    }

    result.goal_bucket = (main_bucket == goal_volume) ? start_bucket : !start_bucket;
    result.other_bucket_liters = (main_bucket == goal_volume) ? side_bucket : main_bucket;
    return result;
}