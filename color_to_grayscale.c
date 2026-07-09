/*
7 kyu
Color to Grayscale
https://www.codewars.com/kata/649c4012aaad69003f1299c1
*/

#include <stdio.h>

#define LIMIT_0_255(X) (X > 255 ? 255 : (X < 0 ? 0 : X))

typedef struct {
  int r, g, b;
} rgb;

void rgb_to_grayscale(const char* color, char* grayscale) {
  rgb c;
  sscanf(color, "#%02x%02x%02x", &c.r, &c.g, &c.b);
  double gd = c.r * 0.299 + c.g * 0.587 + c.b * 0.114 + 0.5;
  int g = LIMIT_0_255((int)gd);
  sprintf(grayscale, "#%02X%02X%02X", g, g, g);
}
