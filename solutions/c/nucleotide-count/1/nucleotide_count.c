#include "nucleotide_count.h"

#include <stdio.h>
#include <stdlib.h>

char* count(const char* dna_strand) {
    int counts[4] = {0, 0, 0, 0};

    while (*dna_strand) {
        switch (*dna_strand) {
            case 'A':
                counts[0]++;
                break;
            case 'C':
                counts[1]++;
                break;
            case 'G':
                counts[2]++;
                break;
            case 'T':
                counts[3]++;
                break;
            default:;
                char* empty = malloc(sizeof(char));
                empty[0] = '\0';
                return empty;
        }

        dna_strand++;
    }

    char* str = malloc(sizeof(char) * 100);
    sprintf(str, "A:%d C:%d G:%d T:%d", counts[0], counts[1], counts[2],
            counts[3]);

    printf("%s\n", str);

    return str;
}
