/*
5 kyu
Perimeter of squares in a rectangle
https://www.codewars.com/kata/559a28007caad2ac4e000083
*/

typedef unsigned long long ull;

ull perimeter(int n) {
  ull a = 1;
  ull s = 1;
  for (int i = 0; i < n + 1; i++) {
    s += a;
    a = s - a;
  }
  return 4 * (s - 1);
}
