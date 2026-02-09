/*
8 kyu
DNA to RNA Conversion
https://www.codewars.com/kata/5556282156230d0e5e000089
*/

#include <stdlib.h>
#include <string.h>

char* dna_to_rna(const char* dna) {
  size_t len = strlen(dna);
  char* result = calloc(len + 1, sizeof(char));
  for (size_t i = 0; i < len; i++)
    result[i] = dna[i] == 'T' ? 'U' : dna[i];
  return result;
}
