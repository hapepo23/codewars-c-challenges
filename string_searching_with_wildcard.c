/*
6 kyu
String searching with wildcard
https://www.codewars.com/kata/546c7f89bed2e12fb300056f
*/

#include <stddef.h>

long long find(const char* needle, const char* haystack) {
  if (*needle == '\0')
    return 0LL;
  for (size_t i = 0; haystack[i] != '\0'; i++) {
    size_t j = 0;
    while (needle[j] != '\0' && haystack[i + j] != '\0' &&
           (needle[j] == '_' || needle[j] == haystack[i + j]))
      j++;
    if (needle[j] == '\0')
      return (long long)i;
  }
  return -1LL;
}
