/*
6 kyu
Continued Fraction
https://www.codewars.com/kata/660e5631b673a8004b71d208
*/

#include <stddef.h>

void continued_fraction(unsigned numer,
                        unsigned denom,
                        unsigned* results,
                        size_t* length) {
  *length = 0;
  if (numer != 0) {
    while (denom) {
      results[(*length)++] = numer / denom;
      unsigned rem = numer % denom;
      numer = denom;
      denom = rem;
    }
  }
}
