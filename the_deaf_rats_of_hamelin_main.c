/*
6 kyu
The Deaf Rats of Hamelin
https://www.codewars.com/kata/598106cb34e205e074000031
*/

#include <stdio.h>

int countDeafRats(const char* town);

static void doTest(int expected, const char* town) {
  int actual = countDeafRats(town);
  printf("Expected %d, but got %d for input: \"%s\" -> %s\n", expected, actual,
         town, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  doTest(0, "~O~O~O~O P");
  doTest(1, "P O~ O~ ~O O~");
  doTest(2, "~O~O~O~OP~O~OO~");
  return 0;
}
