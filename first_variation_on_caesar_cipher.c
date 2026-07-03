/*
5 kyu
First Variation on Caesar Cipher
https://www.codewars.com/kata/5508249a98b3234f420000fb
*/

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static void split5(int total, int* lens) {
  int i;
  int s = total / 5;
  if (total % 5 == 0) {
    for (i = 0; i < 5; i++)
      lens[i] = s;
  } else {
    s += 2;
    do {
      s--;
      int t = total;
      for (i = 0; i < 4; i++) {
        if ((t - s) < 0) {
          lens[i] = t;
          t = 0;
        } else {
          lens[i] = s;
          t -= s;
        }
      }
      lens[4] = total - lens[0] - lens[1] - lens[2] - lens[3];
    } while (lens[4] > lens[3]);
  }
}

char** movingShift(const char* s, int shift) {
  int l = strlen(s);
  int lens[5];
  split5(l, lens);
  char buf[l + 1];
  strcpy(buf, s);
  char* p = buf;
  int temp;
  int c = 0;
  while (*p) {
    if (isupper(*p)) {
      temp = *p - 'A' + (shift + c);
      *p = temp % 26 + 'A';
    } else if (islower(*p)) {
      temp = *p - 'a' + (shift + c);
      *p = temp % 26 + 'a';
    }
    p++;
    c++;
  }
  char** array = malloc(5 * sizeof *array);
  int start = 0;
  for (int i = 0; i < 5; i++) {
    array[i] = calloc(lens[i] + 1, sizeof(char));
    strncpy(array[i], buf + start, lens[i]);
    array[i][lens[i]] = '\0';
    start += lens[i];
  }
  return array;
}

char* demovingShift(const char* const s[5], int shift) {
  int l = strlen(s[0]) * 4 + strlen(s[4]);
  char* result = calloc(l + 1, sizeof(char));
  for (int i = 0; i < 5; i++)
    strcat(result, s[i]);
  char* p = result;
  int c = 0;
  int temp;
  while (*p) {
    if (isupper(*p)) {
      temp = *p - 'A' - (shift + c);
      while (temp < 0)
        temp += 26;
      *p = temp % 26 + 'A';
    } else if (islower(*p)) {
      temp = *p - 'a' - (shift + c);
      while (temp < 0)
        temp += 26;
      *p = temp % 26 + 'a';
    }
    p++;
    c++;
  }
  return result;
}
