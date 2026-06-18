/*
6 kyu
zipWith
https://www.codewars.com/kata/5825792ada030e9601000782
*/

#include <stdio.h>

typedef int (*zipfunc_t)(int, int);

void zip_with(zipfunc_t fn,
              size_t z1,
              const int a1[z1],
              size_t z2,
              const int a2[z2],
              size_t* z3,
              int* a3);

static int add(int a, int b) {
  return a + b;
}

static int sub(int a, int b) {
  return a - b;
}

static int ipow(int a, int b) {
  int c = 1;
  while (b--) {
    c *= a;
  }
  return c;
}

static int max(int a, int b) {
  return a > b ? a : b;
}

void tester(zipfunc_t fn,
            size_t z1,
            const int a1[z1],
            size_t z2,
            const int a2[z2],
            size_t ex,
            const int expected[ex]) {
  size_t ez = z1 < z2 ? z1 : z2;
  size_t sz = 999;
  int submitted[ez];
  zip_with(fn, z1, a1, z2, a2, &sz, submitted);
  for (size_t index = 0; index < ez; index++) {
    char a1_str[9 * z1 + 1];
    size_t position = sprintf(a1_str, "{");
    index = 0;
    while (index < z1) {
      position += sprintf(a1_str + position, "%d, ", a1[index]);
      index += 1;
    }
    sprintf(a1_str + position - 2, "}");
    char a2_str[9 * z2 + 1];
    position = sprintf(a2_str, "{");
    index = 0;
    while (index < z2) {
      position += sprintf(a2_str + position, "%d, ", a2[index]);
      index += 1;
    }
    sprintf(a2_str + position - 2, "}");
    char sub_str[9 * sz + 1];
    position = sprintf(sub_str, "{");
    index = 0;
    while (index < sz) {
      position += sprintf(sub_str + position, "%d, ", submitted[index]);
      index += 1;
    }
    sprintf(sub_str + position - 2, "}");
    char exp_str[9 * ez + 1];
    position = sprintf(exp_str, "{");
    index = 0;
    while (index < ez) {
      position += sprintf(exp_str + position, "%d, ", expected[index]);
      index += 1;
    }
    sprintf(exp_str + position - 2, "}");
    printf("a1 = %s, a2 = %s,\nSubmitted: %s,\nExpected : %s\n\n", a1_str,
           a2_str, sub_str, exp_str);
  }
}

int main(void) {
  {
    const int array1[6] = {0, 1, 2, 3, 4, 5};
    const int array2[6] = {6, 5, 4, 3, 2, 1};
    const int expect[6] = {6, 6, 6, 6, 6, 6};
    tester(add, 6, array1, 6, array2, 6, expect);
  }
  {
    const int array1[5] = {0, 1, 2, 3, 4};
    const int array2[6] = {6, 5, 4, 3, 2, 1};
    const int expect[5] = {6, 6, 6, 6, 6};
    tester(add, 5, array1, 6, array2, 5, expect);
  }
  {
    const int array1[6] = {0, 1, 2, 3, 4, 5};
    const int array2[5] = {6, 5, 4, 3, 2};
    const int expect[5] = {6, 6, 6, 6, 6};
    tester(add, 6, array1, 5, array2, 5, expect);
  }
  {
    const int array1[4] = {10, 10, 10, 10};
    const int array2[4] = {0, 1, 2, 3};
    const int expect[4] = {1, 10, 100, 1000};
    tester(ipow, 4, array1, 4, array2, 4, expect);
  }
  {
    const int array1[6] = {1, 4, 7, 1, 4, 7};
    const int array2[6] = {4, 7, 1, 4, 7, 1};
    const int expect[6] = {4, 7, 7, 4, 7, 7};
    tester(max, 6, array1, 6, array2, 6, expect);
  }
  {
    const int array1[4] = {0, 1, 2, 3};
    const int array2[4] = {0, 1, 2, 3};
    const int expect[4] = {0, 2, 4, 6};
    tester(add, 4, array1, 4, array2, 4, expect);
  }
  {
    const int array1[7] = {10, 10, 10, 10, 10, 10, 10};
    const int array2[7] = {0, 1, 2, 3, 4, 5, 6};
    const int expect[7] = {1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6};
    tester(ipow, 7, array1, 7, array2, 7, expect);
  }
  {
    const int array1[6] = {0, 1, 2, 3, 4, 5};
    const int array2[6] = {6, 5, 4, 3, 2, 1};
    const int expect[6] = {-6, -4, -2, 0, 2, 4};
    tester(sub, 6, array1, 6, array2, 6, expect);
  }
  {
    const int array1[4] = {0, 1, 2, 3};
    const int array2[4] = {0, 1, 2, 3};
    const int expect[4] = {0, 2, 4, 6};
    tester(add, 4, array1, 4, array2, 4, expect);
  }
  return 0;
}
