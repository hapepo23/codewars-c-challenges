/*
6 kyu
Delete occurrences of an element if it occurs more than n times
https://www.codewars.com/kata/554ca54ffa7d91b236000023
*/

#include <stdlib.h>

int* delete_nth(size_t szin, const int order[szin], int max_e, size_t* szout) {
  int* result = malloc(szin * sizeof(int));
  *szout = 0;
  for (size_t i = 0; i < szin; i++) {
    int count = 0;
    for (size_t j = 0; j < *szout; j++)
      if (result[j] == order[i])
        count++;
    if (count < max_e)
      result[(*szout)++] = order[i];
  }
  return result;
}
