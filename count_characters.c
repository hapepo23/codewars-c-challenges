/*
6 kyu
Count characters in your string
https://www.codewars.com/kata/52efefcbcdf57161d4000091
*/

#define COUNTS_SIZE 128

void count(const char* string, unsigned counts[COUNTS_SIZE]) {
  for (unsigned i = 0; i < COUNTS_SIZE; i++) {
    counts[i] = 0;
  }
  while (*string) {
    counts[(int)*string]++;
    string++;
  }
}
