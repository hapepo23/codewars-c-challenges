/*
6 kyu
Equal Sides Of An Array
https://www.codewars.com/kata/5679aa472b8f57fb8c000047
*/

int find_even_index(const int* values, int length) {
  int leftsum = 0, rightsum = 0;
  for (int i = 0; i < length; i++) {
    rightsum += values[i];
  }
  for (int i = 0; i < length; i++) {
    rightsum -= values[i];
    if (leftsum == rightsum)
      return i;
    leftsum += values[i];
  }
  return -1;
}
