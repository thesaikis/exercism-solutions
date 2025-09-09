#include "isogram.h"

bool is_isogram(const char *p) {
    bool s[26] = {0};

    for (; p && *p; p++)
        if ((*p|32) >= 'a' && (*p|32) <= 'z' && (s[(*p|32) - 'a'] ? true : (s[(*p|32) - 'a'] = true, false)))
            return false;

    return p;
}