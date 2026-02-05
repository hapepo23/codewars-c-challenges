/*
5 kyu
Zonk game
https://www.codewars.com/kata/53837b8c94c170e55f000811
*/

#include <stddef.h>
#include <string.h>

int get_score(size_t length, const int dice[length]) {
  int result = 0;
  int counts[6] = {0};
  for (size_t i = 0; i < length; i++)
    counts[dice[i] - 1]++;
  for (int i = 0; i < 6; i++) {
    for (int j = 6; j > 2; j--) {
      if (counts[i] == j) {
        result += (j - 2) * (i == 0 ? 1000 : (i + 1) * 100);
        counts[i] -= j;
      }
    }
  }
  int pairs = 0;
  for (int i = 0; i < 6; i++) {
    if (counts[i] >= 2)
      pairs++;
  }
  if (pairs == 3) {
    result += 750;
    for (int i = 0; i < 6; i++) {
      if (counts[i] >= 2)
        counts[i] -= 2;
    }
  }
  char str[6] = "------";
  for (int i = 0; i < 6; i++) {
    if (counts[i] == 1)
      str[i] = 'x';
    ;
  }
  if (strcmp(str, "xxxxxx") == 0) {
    for (int i = 0; i < 6; i++) {
      counts[i]--;
    }
    result += 1000;
  }
  while (counts[0] > 0) {
    result += 100;
    counts[0]--;
  }
  while (counts[4] > 0) {
    result += 50;
    counts[4]--;
  }
  return result;
}