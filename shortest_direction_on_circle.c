/*
7 kyu
Shortest direction on circle
https://www.codewars.com/kata/686fd320adc800ab627089c2
*/

int shortest_direction(long long a, long long b) {
  long long aa = a % 360;
  long long bb = b % 360;
  int r = (bb - aa) % 360;
  if (r < -180)
    r += 360;
  if (r > 180)
    r -= 360;
  return r;
}
