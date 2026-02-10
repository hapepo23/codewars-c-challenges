/*
7 kyu
Find the next perfect square!
https://www.codewars.com/kata/56269eb78ad2e4ced1000013
*/

#include <math.h>

long int findNextSquare(long int sq) {
  long int root = (long int)sqrt((double)sq);
  if (root * root != sq)
    return -1l;
  else
    return (root + 1l) * (root + 1l);
}
