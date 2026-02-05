/*
5 kyu
Zonk game
https://www.codewars.com/kata/53837b8c94c170e55f000811
*/

#include <stdio.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixed_test(dice, expected) do_test(ARR_LEN(dice), dice, expected)

int get_score(size_t length, const int dice[length]);

static void do_test(size_t length, const int dice[length], int expected) {
  char dice_string[128];
  char* ptr = dice_string;
  ptr += sprintf(ptr, "{");
  for (size_t i = 0; i < length; i++)
    ptr += sprintf(ptr, "%d%s", dice[i], (i == length - 1) ? "" : ", ");
  ptr += sprintf(ptr, "}");
  int actual = get_score(length, dice);
  printf("for dice: %s\nexpected %d, actual %d -> %s\n\n", dice_string,
         expected, actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  fixed_test(((int[]){1}), 100);
  fixed_test(((int[]){2}), 0);
  fixed_test(((int[]){3}), 0);
  fixed_test(((int[]){4}), 0);
  fixed_test(((int[]){5}), 50);
  fixed_test(((int[]){6}), 0);
  fixed_test(((int[]){1, 1}), 200);
  fixed_test(((int[]){1, 1, 1}), 1000);
  fixed_test(((int[]){1, 2, 3, 4, 5, 6}), 1000);
  fixed_test(((int[]){2, 2, 3, 3, 6, 6}), 750);
  fixed_test(((int[]){3, 2, 6, 4, 4, 6}), 0);
  return 0;
}
