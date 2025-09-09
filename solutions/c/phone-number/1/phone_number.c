#include "phone_number.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *phone_number_clean(const char *input) {
    char* res = malloc(sizeof(char) * (PHONE_NUMBER_LEN + 1));
    res[PHONE_NUMBER_LEN] = '\0';

    int len = strlen(input);
    int index = PHONE_NUMBER_LEN - 1;

    // Find the first digit in the phone number, which is the area code
    int i = 0;
    while (input[i] < '0' || input[i] > '9') {
        i++;
    }
    int area_code = input[i];

    // Iterate in reverse and count digits found
    // Also update final result when digit is found
    int digits = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (input[i] >= '0' && input[i] <= '9') {
            if (index >= 0) {
                // Check if the area/exchance code are valid
                if (index == 0 && input[i] < '2') {
                    memset(res, '0', 10);
                    return res;
                } else if (index == 3 && input[i] < '2') {
                    memset(res, '0', 10);
                    return res;
                }
                res[index] = input[i];
                index--;
            }
            digits++;
        }
    }

    // Determine if phone number had correct amount of digits
    // Check the area code if it was 11 digits
    if ((digits != 10 && digits != 11) || (digits == 11 && area_code != '1')) {
        memset(res, '0', 10);
    }

    return res;
}