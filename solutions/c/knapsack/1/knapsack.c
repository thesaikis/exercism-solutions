#include "knapsack.h"

unsigned int maximum_value(unsigned int maximum_weight, item_t* items,
                           size_t item_count) {
    unsigned int dp[item_count + 1][maximum_weight + 1];

    for (size_t i = 0; i <= item_count; i++) {
        dp[i][0] = 0;
    }

    for (size_t w = 0; w <= maximum_weight; w++) {
        dp[0][w] = 0;
    }

    for (size_t i = 1; i <= item_count; i++) {
        for (unsigned int j = 1; j <= maximum_weight; j++) {
            if (items[i - 1].weight > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                unsigned int prev = dp[i - 1][j];
                unsigned int new =
                    dp[i - 1][j - items[i - 1].weight] + items[i - 1].value;
                dp[i][j] = prev > new ? prev : new;
            }
        }
    }

    return dp[item_count][maximum_weight];
}