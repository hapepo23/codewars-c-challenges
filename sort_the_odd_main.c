/*
6 kyu
Sort the odd
https://www.codewars.com/kata/578aa45ee9fd15ff4600090d
*/

#include <stdio.h>
#include <string.h>

void sort_array(size_t n, int arr[n]);

static void atos(const int* arr, const size_t n, char* string) {
  for (size_t i = 0; i < n; i++)
    string += sprintf(string, "%s%i%s", i == 0 ? "[" : "", arr[i],
                      i == n - 1 ? "]" : ", ");
}

static void do_test(size_t n, int arr[n], const int* expected) {
  char arr_str[128] = {0}, result_str[128] = {0}, expected_str[128] = {0};
  atos(arr, n, arr_str);
  sort_array(n, arr);
  atos(arr, n, result_str);
  atos(expected, n, expected_str);
  printf("Sorting array %s:\nexpected: %s\nactual  : %s\n%s\n\n", arr_str,
         expected_str, result_str,
         strcmp(expected_str, result_str) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test(6, (int[]){5, 3, 2, 8, 1, 4}, (const int[]){1, 3, 2, 8, 5, 4});
  do_test(5, (int[]){5, 3, 1, 8, 0}, (const int[]){1, 3, 5, 8, 0});
  do_test(0, (int[]){}, (const int[]){});
  return 0;
}
