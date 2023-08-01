#include <stdio.h>
#include <string.h>
#include "genetic_code.h"

void initGeneticCode(struct GeneticCodeEntry *code) {
    const *char codons[64] = {
        "UUU", "UUC", "UUA", "UUG", "CUU", "CUC", "CUA", "CUG",
        "AUU", "AUC", "AUA", "AUG", "GUU", "GUC", "GUA", "GUG",
        "UCU", "UCC", "UCA", "UCG", "CCU", "CCC", "CCA", "CCG",
        "ACU", "ACC", "ACA", "ACG", "GCU", "GCC", "GCA", "GCG",
        "UAU", "UAC", "UAA", "UAG", "CAU", "CAC", "CAA", "CAG",
        "AAU", "AAC", "AAA", "AAG", "GAU", "GAC", "GAA", "GAG",
        "UGU", "UGC", "UGA", "UGG", "CGU", "CGC", "CGA", "CGG",
        "AGU", "AGC", "AGA", "AGG", "GGU", "GGC", "GGA", "GGG"
    };

    const char aminoAcids[64] = {
        'F', 'F', 'L', 'L', 'L', 'L', 'L', 'L',
        'I', 'I', 'I', 'M', 'V', 'V', 'V', 'V',
        'S', 'S', 'S', 'S', 'P', 'P', 'P', 'P',
        'T', 'T', 'T', 'T', 'A', 'A', 'A', 'A',
        'Y', 'Y', '_', '_', 'H', 'H', 'Q', 'Q',
        'N', 'N', 'K', 'K', 'D', 'D', 'E', 'E',
        'C', 'C', '_', 'W', 'R', 'R', 'R', 'R',
        'S', 'S', 'R', 'R', 'G', 'G', 'G', 'G'
    };

    for (int i = 0; i < 64; i++) {
        strcpy(code[i].codon, codons[i]);
        code[i].aminoAcid = aminoAcids[i];
    }
}

char rnaToAminoAcids(const char *rna, struct GeneticCodeEntry *code) {
    int rnaSize = strlen(rna);
    char *aminoAcids = (char*)malloc(sizeof(char) * (rnaSize / 3 + 1));
    int aminoAcidsIndex = 0;

    for (int i = 0; i < rnaSize; i += 3) {
        char codon[4] = {rna[i], rna[i + 1], rna[i + 2], '\0'};
        char aminoAcid = 'X';

        for (int j = 0; j < 64; j++) {
            if (strcmp(codon, code[j].codon) == 0) {
                aminoAcid = code[j].aminoAcid;
                break;
            }
        }

        aminoAcids[aminoAcidsIndex++] = aminoAcid;
    }

    aminoAcids[aminoAcidsIndex] = '\0';

    return aminoAcids;

}