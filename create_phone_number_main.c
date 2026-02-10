/*
6 kyu
Create Phone Number
https://www.codewars.com/kata/525f50e3b73515a6db000b83
*/

#include <inttypes.h>
#include <stdio.h>
#include <string.h>

char* create_phone_number(char phnum[15], const uint8_t nums[10]);

static void do_test(const uint8_t digits[10], const char expected[15]) {
  char user_string[15] = "@@@@@@@@@@@@@@";
  char* actual = create_phone_number(user_string, digits);
  printf(
      "input {%hhu, %hhu, %hhu, %hhu, %hhu, %hhu, %hhu, %hhu, %hhu, %hhu}\n"
      "expected \"%s\"\nactual   \"%s\"\n%s\n\n",
      digits[0], digits[1], digits[2], digits[3], digits[4], digits[5],
      digits[6], digits[7], digits[8], digits[9], expected, actual,
      strcmp(actual, expected) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test((uint8_t[10]){1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, "(123) 456-7890");
  do_test((uint8_t[10]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, "(111) 111-1111");
  return 0;
}
