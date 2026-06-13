/*
6 kyu
Cantor's pairing function
https://www.codewars.com/kata/543b9113def6343e43000875
*/

#include <math.h>
#include <stdio.h>

void cantor_pairing_function(char* output, unsigned n) {
  unsigned nom, diag, low, high;
  diag = ceil((sqrt(1 + 8 * n) - 1) / 2);
  high = (diag + 1) * diag / 2;
  low = high + 1 - diag;
  if (diag % 2 == 0)
    nom = n - low + 1;
  else
    nom = high - n + 1;
  sprintf(output, "%u/%u", nom, diag - nom + 1);
}
