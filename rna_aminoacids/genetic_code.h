#ifndef GENETIC_CODE_H
#define GENETIC_CODE_H

struct GeneticCodeEntry {
    char codon[4];
    char aminoAcid;
};

void initGeneticCode(struct GeneticCodeEntry *code);

char* rnaToAminoAcids(const char *rna, struct GeneticCodeEntry *code);

#endif