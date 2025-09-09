#include "armstrong_numbers.h"

#include <math.h>

bool is_armstrong_number(int candidate) {
    int sum = 0;
    int temp = candidate;
    int digit;
    int num_length = floor(log10(candidate)) + 1;
    
    while (temp > 0) {
        digit = temp % 10;
        sum += pow(digit, num_length);
        temp /= 10;
    }

    return sum == candidate;
}