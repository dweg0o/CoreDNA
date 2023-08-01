#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dna_rna.h"

void dnaToRna(char *dna) {
    int length = strlen(dna);

    char *rna = (char*)malloc(sizeof(char) * (length + 1));

    for (int i = 0; i < length; i++) {
        char base = dna[i];
        char complement;

        switch (base) {
        case 'A':
            complement = 'U';
            break;

        case 'T':
            complement = 'A';
            break;

        case 'C':
            complement = 'G';
            break;
        
        case 'G':
            complement = 'C';
            break;
        
        default:
            complement = 'X';
            break;
        }

        rna[i] = complement;
    }

    rna[length] = '\0';
    
    free(rna);
}