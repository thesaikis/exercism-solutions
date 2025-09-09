#include "rna_transcription.h"

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char *to_rna(const char *dna) {
    size_t length = strlen(dna);
    char *rna = malloc(sizeof(char) * (length + 1));
    rna[length] = '\0';

    for (size_t i = 0; i < length; i++) {
        if (dna[i] == 'G') {
            rna[i] = 'C';
        } else if (dna[i] == 'C') {
            rna[i] = 'G';
        } else if (dna[i] == 'T') {
            rna[i] = 'A';
        } else {
            rna[i] = 'U';
        }
    }

    return rna;
}
