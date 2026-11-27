/*
8 kyu
Well of Ideas - Easy Version
https://www.codewars.com/kata/57f222ce69e09c3630000212
*/

#include <stddef.h>
#include <string.h>

const char* well(size_t n, const char* const ideas[n]) {
  static const char* const fail = "Fail!";
  static const char* const publish = "Publish!";
  static const char* const series = "I smell a series!";
  unsigned count = 0;
  for (size_t i = 0; i < n; i++)
    if (strcmp(ideas[i], "good") == 0)
      count++;
  return count == 0 ? fail : (count > 2 ? series : publish);
}
