#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dna_rna/dna_rna.h"
#include "rna_complement/rna_complement.h"
#include "rna_identification/rna_identification.h"
#include "rna_aminoacids/genetic_code.h"

int main(int argc, char *argv[]) {

    printf("Bioinformatics Pipeline Demo v1.0\n\n");
    if (argc < 2) {
        printf("Usage: %s <DNA_SEQUENCE>\n", argv[0]);
        return 1;
    }

    const char *dnaSequence = argv[1];

    printf("Project 1: DNA to RNA\n");
    printf("DNA sequence: %s\n", dnaSequence);

    char *rnaSequence = dnaToRna(dnaSequence);
    if (!rnaSequence) {
        printf("Error converting DNA to RNA.\n");
        return 1;
    }

    printf("RNA sequence: %s\n\n", rnaSequence);

    printf("Project 2: RNA Complement\n");
    char *complement = complementRna(rnaSequence);
    if (!complement) {
        printf("Error generating RNA complement.\n");
        free(rnaSequence);
        return 1;
    }

    printf("RNA complement: %s\n\n", complement);

    printf("Project 3: RNA Identification\n");
    char identification = identifyRna(rnaSequence);
    printf("RNA identification: %c\n\n", identification);

    printf("Project 4: RNA to Amino Acids Translation\n");

    struct GeneticCodeEntry code[64];
    initGeneticCode(code);

    char *aminoAcids = rnaToAminoAcids(rnaSequence, code);
    if (!aminoAcids) {
        printf("Error translating RNA to amino acids.\n");
        free(rnaSequence);
        free(complement);
        return 1;
    }

    printf("Amino acids sequence: %s\n", aminoAcids);

    free(rnaSequence);
    free(complement);
    free(aminoAcids);

    return 0;
}
