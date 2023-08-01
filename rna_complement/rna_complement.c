#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rnaComplement(char *rna) {
    int rnaSize = strlen(rna);
    char rnaVect = (char*) malloc(sizeof(char) * rnaSize + 1);

    strcpy(rnaVect, rna)

    for (int i = 0; i < rnaSize; i++) {
        char base = rnaVect[i];
        char complement;

        switch (base)
        {
        case 'A':
            complement = 'U';
            break;

        case 'U':
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
    
    }
    rnaVect[rnaSize] = '\0'; 

    free(rnaVect);
}