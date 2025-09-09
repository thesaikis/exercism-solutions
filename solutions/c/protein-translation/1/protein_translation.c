#include "protein_translation.h"

#include <stdio.h>
#include <string.h>

static protein_t check_protein(const char* sequence) {
    if (strncmp(sequence, "AUG", 3) == 0)
        return Methionine;
    else if (strncmp(sequence, "UUU", 3) == 0 ||
             strncmp(sequence, "UUC", 3) == 0)
        return Phenylalanine;
    else if (strncmp(sequence, "UUA", 3) == 0 ||
             strncmp(sequence, "UUG", 3) == 0)
        return Leucine;
    else if (strncmp(sequence, "UCU", 3) == 0 ||
             strncmp(sequence, "UCC", 3) == 0 ||
             strncmp(sequence, "UCA", 3) == 0 ||
             strncmp(sequence, "UCG", 3) == 0)
        return Serine;
    else if (strncmp(sequence, "UAU", 3) == 0 ||
             strncmp(sequence, "UAC", 3) == 0)
        return Tyrosine;
    else if (strncmp(sequence, "UGU", 3) == 0 ||
             strncmp(sequence, "UGC", 3) == 0)
        return Cysteine;
    else if (strncmp(sequence, "UGG", 3) == 0)
        return Tryptophan;
    else if (strncmp(sequence, "UAA", 3) == 0 ||
             strncmp(sequence, "UAG", 3) == 0 ||
             strncmp(sequence, "UGA", 3) == 0)
        return -1;

    return -2;
}

proteins_t proteins(const char* sequence) {
    proteins_t res = {0};
    int len = strlen(sequence);

    for (int i = 0; i < len; i += 3) {
        if (i + 3 > len) return res;

        protein_t protein = check_protein(sequence + i);
        if ((int)protein == -1) break;
        if ((int)protein == -2) return res;
        res.proteins[res.count++] = protein;
    }

    res.valid = true;
    return res;
}
