#include "bob.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

static int str_isupper(char *phrase) {
    int found_upper = 0;  // Flag to check if any uppercase is found.

    while (*phrase) {
        if (isalpha(*phrase) && islower(*phrase)) return 0;
        found_upper = isupper(*phrase) || found_upper;
        phrase++;
    }

    return found_upper;
}

static int str_isspace(char *phrase) {
    while (*phrase++) {
        if (!isspace(*(phrase - 1))) return 0;
    }

    return 1;
}

static int isquestion(char *phrase) {
    char *question_loc = strrchr(phrase, '?');

    if (!question_loc) return 0;
    if (question_loc && *(question_loc + 1) == '\0') return 1;

    question_loc++;
    while (*question_loc) {
        if (!isspace(*question_loc)) return 0;
        question_loc++;
    }

    return 1;
}

char *hey_bob(char *greeting) {
    int upper = str_isupper(greeting);
    int space = str_isspace(greeting);
    int question = isquestion(greeting);

    if (space)
        return "Fine. Be that way!";
    else if (upper && question)
        return "Calm down, I know what I'm doing!";
    else if (upper)
        return "Whoa, chill out!";
    else if (question)
        return "Sure.";

    return "Whatever.";
}