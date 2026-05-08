/*
4 kyu
Next smaller number with the same digits
https://www.codewars.com/kata/5659c6d896bc135c4c00021e
*/

#include <stdbool.h>
#include <stdio.h>

typedef long long ll;
typedef unsigned long long ull;

ll next_smaller_number(ull n) {
  char s[32], tmp;
  int i, j, len;
  int best = -1;
  bool found = false;
  ll result;
  len = sprintf(s, "%llu", n);
  for (i = len - 2; i >= 0; i--)
    if (s[i] > s[i + 1])
      break;
  if (i < 0)
    return -1;
  for (j = i + 1; j < len; j++)
    if (s[j] < s[i])
      if (best == -1 || s[j] >= s[best])
        best = j;
  if (i == 0 && s[best] == '0') {
    for (j = i + 1; j < len; j++)
      if (s[j] < s[i] && s[j] != '0')
        if (!found || s[j] >= s[best]) {
          best = j;
          found = true;
        }
    if (!found)
      return -1;
  }
  tmp = s[i];
  s[i] = s[best];
  s[best] = tmp;
  for (j = i + 1; j < len - 1; j++)
    for (int k = j + 1; k < len; k++)
      if (s[j] < s[k]) {
        tmp = s[j];
        s[j] = s[k];
        s[k] = tmp;
      }
  sscanf(s, "%lld", &result);
  return result;
}