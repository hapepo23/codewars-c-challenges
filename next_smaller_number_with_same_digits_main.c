/*
4 kyu
Next smaller number with the same digits
https://www.codewars.com/kata/5659c6d896bc135c4c00021e
*/

#include <stdio.h>

typedef long long ll;
typedef unsigned long long ull;

ll next_smaller_number(ull n);

static void dotest(ull n, ll expected) {
  ll submitted = next_smaller_number(n);
  printf("Input = %llu, submitted: %lld, expected: %lld -> %s\n", n, submitted,
         expected, submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  dotest(21, 12);
  dotest(907, 790);
  dotest(531, 513);
  dotest(1027, -1);
  dotest(441, 414);
  dotest(123456798, 123456789);
  return 0;
}
