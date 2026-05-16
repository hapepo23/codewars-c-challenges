/*
7 kyu
Maximum Triplet Sum
https://www.codewars.com/kata/5aa1bcda373c2eb596000112
*/

#include <stdlib.h>
#include <string.h>

static int compare(const void* a, const void* b) {
  return (*(int*)a < *(int*)b) - (*(int*)a > *(int*)b);
}

int maxTriSum(const int numbers[], int count) {
  int sorted[count];
  qsort(memcpy(sorted, numbers, sizeof(sorted)), count, sizeof(int), compare);
  int last = sorted[0];
  int result = sorted[0];
  int c = 1;
  for (int i = 1; i < count; i++) {
    if (sorted[i] != last) {
      c++;
      result += sorted[i];
      if (c == 3)
        break;
      last = sorted[i];
    }
  }
  return result;
}
