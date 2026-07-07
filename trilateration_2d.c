/*
6 kyu
Locate P using 3 Points and their distances to P
https://www.codewars.com/kata/6326533f8b7445002e856ca3
*/

typedef struct {
  long long x;
  long long y;
} Point2;

Point2 triangulate(Point2 A,
                   long long dA,
                   Point2 B,
                   long long dB,
                   Point2 C,
                   long long dC) {
  long long a, b, c, d, e, f, g;
  a = 2 * (B.x - A.x);
  b = 2 * (B.y - A.y);
  c = 2 * (C.x - A.x);
  d = 2 * (C.y - A.y);
  e = dA - dB + B.x * B.x - A.x * A.x + B.y * B.y - A.y * A.y;
  f = dA - dC + C.x * C.x - A.x * A.x + C.y * C.y - A.y * A.y;
  g = a * d - b * c;
  return (Point2){.x = (d * e - b * f) / g, .y = (a * f - c * e) / g};
}
