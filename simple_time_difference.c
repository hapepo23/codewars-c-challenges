/*
6 kyu
Simple time difference
https://www.codewars.com/kata/5b76a34ff71e5de9db0000f2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

char* solve(const char* const arr[], size_t arr_length) {
  char* result = calloc(6, sizeof(char));
  if (arr_length == 1) {
    strcpy(result, "23:59");
  } else {
    unsigned* mins = calloc(arr_length, sizeof(unsigned));
    for (size_t i = 0; i < arr_length; i++) {
      mins[i] = 60 * ((arr[i][0] - '0') * 10 + (arr[i][1] - '0')) +
                ((arr[i][3] - '0') * 10 + (arr[i][4] - '0'));
    }
    qsort(mins, arr_length, sizeof(unsigned), compare);
    unsigned minsresult = 0;
    for (size_t i = 0; i < arr_length; i++) {
      unsigned diff = (i == 0) ? (mins[i] + 1440 - mins[arr_length - 1])
                               : (mins[i] - mins[i - 1]);
      if (diff > 0) {
        diff--;
        if (diff > minsresult)
          minsresult = diff;
      }
    }
    free(mins);
    sprintf(result, "%02d:%02d", (minsresult / 60) % 24, minsresult % 60);
  }
  return result;
}
