#include <stdio.h>
#include <string.h>
#include <rna_identification.h>

char identifyRna(const char *rna) {
    int rnaSize = strlen(rna);

    if (rnaSize >= 3 && strcmp(rna, "AUG", 3) == 0) {
        if (strncmp(rna + rnaSize - 3, "UAA", 3) == 0 ||
            strncmp(rna + rmaSize - 3, "UAG", 3) == 0 ||
            strncmp(rna + rnaSize - 3, "UGA", 3) == 0 ) {
            return 'V';
        } else {
            return 'I';
        }
    } else {
        return 'I';
    }
}