/*
7 kyu
Sorting the Odd way!
https://www.codewars.com/kata/57fb79784e2d0639c9000066
*/

#include <stdbool.h>
#include <stdlib.h>

static int compare(const void* a, const void* b) {
  double da = *(double*)a;
  double db = *(double*)b;
  bool odda = (int)da % 2;
  bool oddb = (int)db % 2;
  if (odda != oddb)
    return odda ? -1 : 1;
  else if (odda)
    return da > db ? 1 : (da == db ? 0 : -1);
  return da > db ? -1 : (da == db ? 0 : 1);
}

void sort_it_out(size_t length,
                 const double array[length],
                 double sorted[length]) {
  for (size_t i = 0; i < length; i++)
    sorted[i] = array[i];
  qsort(sorted, length, sizeof(double), compare);
}
