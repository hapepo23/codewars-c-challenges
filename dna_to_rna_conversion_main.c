/*
8 kyu
DNA to RNA Conversion
https://www.codewars.com/kata/5556282156230d0e5e000089
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* dna_to_rna(const char*);

int main(void) {
  char* dna[] = {"TTTT", "GCAT", "GACCGCCGCC"};
  char* rna[] = {"UUUU", "GCAU", "GACCGCCGCC"};
  char *actual, *expected;
  size_t n;
  for (n = 0; n < 3; ++n) {
    actual = dna_to_rna(*(dna + n));
    expected = *(rna + n);
    printf("DNA: %s, RNA-expected: %s, RNA-actual: %s -> %s\n", *(dna + n),
           expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
    free(actual);
  }
  return 0;
}
