#include <stdio.h>
#include <stdlib.h>
#include "dna_rna/dna_rna.h"
#include "rna_complement/rna_complement.h"
#include "rna_identification/rna_identification.h"
#include "rna_aminoacids/genetic_code.h"

int main() {
    char dnaSequence[] = "ATGCTAGCTA";
    printf("Projeto 1: DNA para RNA\n");
    printf("Sequência de DNA: %s\n", dnaSequence);
    char *rnaSequence = dnaToRna(dnaSequence);
    printf("Sequência de RNA: %s\n\n", rnaSequence);
    free(rnaSequence);

    char rnaComplementSequence[] = "AUGCUAGCUA";
    printf("Projeto 2: Complemento de RNA\n");
    printf("Sequência de RNA: %s\n", rnaComplementSequence);
    char *complement = complementRna(rnaComplementSequence);
    printf("Complemento de RNA: %s\n\n", complement);
    free(complement);

    char rnaIdentificationSequence[] = "AUGCUAGCUAUAG";
    printf("Projeto 3: Identificação de RNA\n");
    printf("Sequência de RNA: %s\n", rnaIdentificationSequence);
    char identification = identifyRna(rnaIdentificationSequence);
    printf("Identificação de RNA: %c\n\n", identification);

    struct GeneticCodeEntry code[64];
    initGeneticCode(code);
    const char *rnaTranslationSequence = "AUGUUUUUCUGU"; 
    printf("Projeto 4: Tradução de RNA para Aminoácidos\n");
    printf("Sequência de RNA: %s\n", rnaTranslationSequence);
    char *aminoAcids = rnaToAminoAcids(rnaTranslationSequence, code);
    printf("Sequência de Aminoácidos: %s\n", aminoAcids);
    free(aminoAcids);

    return 0;
}
