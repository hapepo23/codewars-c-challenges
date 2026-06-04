/*
6 kyu
For whom the Bell tolls
https://www.codewars.com/kata/62665d43e67fbaf7b37212d2
*/

void bell(unsigned n, unsigned* array) {
  for (unsigned i = 1; i <= n; i++)
    *(array + i - 1) = i * (n + 1 - i);
}
