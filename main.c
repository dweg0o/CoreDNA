#include <stdio.h>
#include <stdlib.h>
#include "dna_rna/dna_rna.h"
#include "rna_complement/rna_complement.h"
#include "rna_identification/rna_identification.h"
#include "rna_aminoacids/genetic_code.h"

int main() {
    char dnaSequence[] = "ATGCTAGCTA";
    printf("Project 1: DNA to RNA\n");
    printf("DNA sequence: %s\n", dnaSequence);

    char *rnaSequence = dnaToRna(dnaSequence);
    printf("RNA sequence: %s\n\n", rnaSequence);
    free(rnaSequence);

    char rnaComplementSequence[] = "AUGCUAGCUA";
    printf("Project 2: RNA Complement\n");
    printf("RNA sequence: %s\n", rnaComplementSequence);

    char *complement = complementRna(rnaComplementSequence);
    printf("RNA complement: %s\n\n", complement);
    free(complement);

    char rnaIdentificationSequence[] = "AUGCUAGCUAUAG";
    printf("Project 3: RNA Identification\n");
    printf("RNA sequence: %s\n", rnaIdentificationSequence);

    char identification = identifyRna(rnaIdentificationSequence);
    printf("RNA identification: %c\n\n", identification);

    struct GeneticCodeEntry code[64];
    initGeneticCode(code);

    const char *rnaTranslationSequence = "AUGUUUUUCUGU";
    printf("Project 4: RNA to Amino Acids Translation\n");
    printf("RNA sequence: %s\n", rnaTranslationSequence);

    char *aminoAcids = rnaToAminoAcids(rnaTranslationSequence, code);
    printf("Amino acids sequence: %s\n", aminoAcids);
    free(aminoAcids);

    return 0;
}
