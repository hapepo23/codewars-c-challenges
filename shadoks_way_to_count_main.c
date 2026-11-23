/*
7 kyu
Shadok's way to count
https://www.codewars.com/kata/6b00d45ad1103df1762bded3
*/

#include <math.h>
#include <stdio.h>
#include <string.h>

void shadok(unsigned number, char* result);

static void tester(unsigned number, const char* expected) {
  size_t req_mem = 3 + (number ? (log(number) / log(4)) * 3 : 0);
  char submitted[req_mem];
  memset(submitted, '*', req_mem * sizeof(char));
  shadok(number, submitted);
  printf("Number = %u, actual = %s, expected = %s -> %s\n", number, submitted,
         expected, strcmp(submitted, expected) == 0 ? "OK" : "FAIL");
}

int main(void) {
  tester(0, "GA");
  tester(1, "BU");
  tester(2, "ZO");
  tester(3, "MEU");
  tester(7, "BUMEU");
  tester(33, "ZOGABU");
  tester(356, "BUBUZOBUGA");
  tester(3772, "MEUZOZOMEUMEUGA");
  tester(12345, "MEUGAGAGAMEUZOBU");
  tester(4294967295, "MEUMEUMEUMEUMEUMEUMEUMEUMEUMEUMEUMEUMEUMEUMEUMEU");
  return 0;
}
