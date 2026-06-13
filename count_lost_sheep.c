/*
7 kyu
Count all the sheep on farm in the heights of New Zealand
https://www.codewars.com/kata/58e0f0bf92d04ccf0a000010
*/

// friday and saturday are 0-terminated arrays,
// i.e. the last element (and only that) will be 0.

int lostSheep(const int* friday, const int* saturday, int total) {
  int result = total;
  while (*friday)
    result -= *(friday++);
  while (*saturday)
    result -= *(saturday++);
  return result;
}
