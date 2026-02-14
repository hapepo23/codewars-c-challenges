/*
6 kyu
Multiplication table
https://www.codewars.com/kata/534d2f5b5371ecf8d2000a08
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** multiplication_table(int n);

void do_test(int n, const int expected[n][n]) {
  int** actual = multiplication_table(n);
  if (n) {
    printf("Expected: \n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        printf("%5d ", expected[i][j]);
      puts("");
    }
    printf("Actual: \n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        printf("%5d ", actual[i][j]);
      puts("");
    }
    int ok = 0;
    for (int i = 0; i < n; i++) {
      if (memcmp(actual[i], expected[i], sizeof(int) * n) == 0)
        ok++;
      free(actual[i]);
    }
    printf("%s\n\n", ok == n ? "OK" : "FAIL");
    free(actual);
  }
}

int main(void) {
  {
    const int expected[3][3] = {{1, 2, 3}, {2, 4, 6}, {3, 6, 9}};
    int n = 3;
    do_test(n, expected);
  }
  {
    const int expected[4][4] = {
        {1, 2, 3, 4}, {2, 4, 6, 8}, {3, 6, 9, 12}, {4, 8, 12, 16}};
    int n = 4;
    do_test(n, expected);
  }
  return 0;
}
