/*
4 kyu
The observed PIN
https://www.codewars.com/kata/5263c6999e0f40dee200059d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int poss[10][6] = {
    // length, possibilities - for 0..9
    {2, 0, 8},          {3, 1, 2, 4},       {4, 1, 2, 3, 5}, {3, 2, 3, 6},
    {4, 1, 4, 5, 7},    {5, 2, 4, 5, 6, 8}, {4, 3, 5, 6, 9}, {3, 4, 7, 8},
    {5, 5, 7, 8, 9, 0}, {3, 6, 8, 9}};

static size_t currentcount;

static void adddigit(int pos,
                     int digit,
                     int factor,
                     int posscnt,
                     char** result) {
  for (size_t i = 0; i < currentcount; i++) {
    int k = (i / factor) % posscnt;
    result[i][pos] = poss[digit][k + 1] + '0';
  }
}

const char** get_pins(const char* observed, size_t* count) {
  size_t l = strlen(observed);
  int digits[l];
  int posscnt[l];
  int factor[l];
  currentcount = 1;
  for (size_t i = 0; i < l; i++) {
    digits[i] = observed[i] - '0';
    posscnt[i] = poss[digits[i]][0];
    factor[i] = 1;
    for (size_t j = 0; j < i; j++) {
      factor[j] *= posscnt[i];
    };
    currentcount *= posscnt[i];
  }
  for (size_t i = 0; i < l; i++) {
  }
  char** result = (char**)malloc(sizeof(char*) * currentcount);
  for (size_t i = 0; i < currentcount; i++) {
    result[i] = (char*)calloc(l + 1, sizeof(char));
  }
  for (size_t i = 0; i < l; i++) {
    adddigit(i, digits[i], factor[i], posscnt[i], result);
  }
  *count = currentcount;
  return (const char**)result;
}

void free_pins(const char** pins) {
  for (size_t i = 0; i < currentcount; i++)
    free((void*)pins[i]);
  free(pins);
}
