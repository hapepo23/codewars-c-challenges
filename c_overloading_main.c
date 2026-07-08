/*
6 kyu
C overloading
https://www.codewars.com/kata/625eb7850e2c2f000eca370c
*/

#include <stdio.h>
#include <string.h>
#include "c_overloading.h"

int main(void) {
  printf("%s\n", add(10, 25) == 35 ? "OK" : "FAIL");
  printf("%s\n",
         strcmp(add((char[64]){"10"}, 25), "1025") == 0 ? "OK" : "FAIL");
  printf("%s\n",
         strcmp(add(10, (char[64]){"25"}), "1025") == 0 ? "OK" : "FAIL");
  printf("%s\n",
         strcmp(add((char[64]){"10"}, "25"), "1025") == 0 ? "OK" : "FAIL");
  char string[64] = "abc";
  printf("%s\n", add(string, 10) == string ? "OK" : "FAIL");
  printf("%s\n", add(10, string) == string ? "OK" : "FAIL");
  printf("%s\n", add(string, "def") == string ? "OK" : "FAIL");
  return 0;
}
