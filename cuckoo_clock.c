/*
6 kyu
Cuckoo Clock
https://www.codewars.com/kata/656e4602ee72af0017e37e82
*/

#include <stdio.h>

static int minutes_since_one_hour(const char* time) {
  int h, m, result;
  sscanf(time, "%02d:%02d", &h, &m);
  result = (h - 1) * 60 + m;
  return result;
}

static int chimes_since_one_hour(const int mins) {
  int result, a = (mins - 1) / 60;
  result = (mins + 14) / 15 + a * (a + 1) / 2;
  return result;
}

static int chimes_to_mins_since_one_hour(int chimes) {
  int quarter, lastc = -1, c, result = 0;
  chimes = chimes % 114;
  for (quarter = 0; quarter <= 47; quarter++) {
    c = chimes_since_one_hour(quarter * 15);
    if (chimes > lastc && chimes <= c) {
      result = (quarter - 1) * 15;
      if (result < 0)
        result = 720 + result;
      return result;
    } else
      lastc = c;
  }
  return result;
}

static void mins_to_time_string(const int mins, char* output_time) {
  sprintf(output_time, "%02d:%02d", 1 + mins / 60, mins % 60);
}

void cuckoo_clock(const char* initial_time, int n, char* output_time) {
  mins_to_time_string(
      chimes_to_mins_since_one_hour(
          chimes_since_one_hour(minutes_since_one_hour(initial_time)) + n),
      output_time);
}
