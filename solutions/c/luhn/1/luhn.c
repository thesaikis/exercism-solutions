#include "luhn.h"

#include <ctype.h>
#include <string.h>

bool luhn(const char *num) {
    size_t len = strlen(num);
    if (len <= 1) return false;

    int sum = 0;
    bool do_double = false;
    int valid_found = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(num[i])) {
            int new_num = (num[i] - '0') * (do_double ? 2 : 1);
            sum += new_num > 9 ? new_num - 9 : new_num;
            do_double = !do_double;
            valid_found++;
        } else if (!isspace(num[i]))
            return false;
    }

    return valid_found > 1 && sum % 10 == 0;
}