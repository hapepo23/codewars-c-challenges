/*
6 kyu
Matrix Rotation
https://www.codewars.com/kata/593e978a3bb47a8308000b8f
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define ARR_LEN(array) (sizeof(array) / sizeof(*(array)))
#define fixed_test(input, expected) \
  do_test(ARR_LEN(input), input, ARR_LEN(expected), expected)

char** rotate_clockwise(size_t rows_in,
                        const char* const matrix[rows_in],
                        size_t* rows_out);
void free_matrix(size_t rows, char* matrix[rows]);

static void print_array(size_t rows, const char* const matrix[rows]) {
  printf("{ ");
  for (size_t i = 0; i < rows; i++)
    printf("\"%s\"%s", matrix[i], (i == rows - 1) ? "" : ", ");
  printf(" }");
}

static bool arrays_equal(size_t len_a,
                         const char* const a[len_a],
                         size_t len_b,
                         const char* const b[len_b]) {
  if (len_a != len_b)
    return false;
  for (size_t i = 0; i < len_a; i++)
    if (strcmp(a[i], b[i]))
      return false;
  return true;
}

static void do_test(size_t len_in,
                    const char* const input[len_in],
                    size_t len_exp,
                    const char* const expected[len_exp]) {
  size_t len_act = 42;
  char** const actual = rotate_clockwise(len_in, input, &len_act);
  const bool equal =
      arrays_equal(len_act, (const char**)actual, len_exp, expected);
  printf("Input    = ");
  print_array(len_in, input);
  printf("\nExpected = ");
  print_array(len_exp, expected);
  printf("\nActual   = ");
  print_array(len_act, (const char**)actual);
  printf("\n-> %s\n\n", equal ? "OK" : "FAIL");
  free_matrix(len_act, actual);
}

int main(void) {
  do_test(0, NULL, 0, NULL);
  do_test(1, (const char* [1]){""}, 0, NULL);
  do_test(3, (const char* [3]){"", "", ""}, 0, NULL);
  fixed_test(((const char*[]){"a", "b", "c"}), ((const char*[]){"cba"}));
  fixed_test(((const char*[]){"cba"}), ((const char*[]){"c", "b", "a"}));
  fixed_test(((const char*[]){"c", "b", "a"}), ((const char*[]){"abc"}));
  fixed_test(((const char*[]){"abc", "def"}),
             ((const char*[]){"da", "eb", "fc"}));
  fixed_test(((const char*[]){
                 "###.....",
                 "..###...",
                 "....###.",
                 ".....###",
                 ".....###",
                 "....###.",
                 "..###...",
                 "###.....",
             }),
             ((const char*[]){
                 "#......#",
                 "#......#",
                 "##....##",
                 ".#....#.",
                 ".##..##.",
                 "..####..",
                 "..####..",
                 "...##...",
             }));
  fixed_test(((const char*[]){
                 "---***---",
                 "--**.**--",
                 "--*...*--",
                 "--*...*--",
                 "--**.**--",
                 "---***---",
             }),
             ((const char*[]){
                 "------",
                 "------",
                 "-****-",
                 "**..**",
                 "*....*",
                 "**..**",
                 "-****-",
                 "------",
                 "------",
             }));
  fixed_test(((const char*[]){
                 "\\.../",
                 ".\\./.",
                 "..X..",
                 "./.\\.",
                 "/...\\",
             }),
             ((const char*[]){
                 "/...\\",
                 "./.\\.",
                 "..X..",
                 ".\\./.",
                 "\\.../",
             }));
  fixed_test(((const char*[]){
                 "######",
                 "#....#",
                 "#.**.#",
                 "#.**.#",
                 "#....#",
                 "######",
             }),
             ((const char*[]){
                 "######",
                 "#....#",
                 "#.**.#",
                 "#.**.#",
                 "#....#",
                 "######",
             }));
  return 0;
}
