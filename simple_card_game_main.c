/*
6 kyu
Simple card game
https://www.codewars.com/kata/53417de006654f4171000587
*/

#include <stdio.h>
#include <string.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixed_test(steve, josh, expected) \
  do_test(ARR_LEN(steve), steve, josh, expected)

char* game_outcome(size_t n,
                   const char steve[n],
                   const char josh[n],
                   char* outcome);

static void print_array(size_t length, const char array[length]) {
  printf("{");
  for (size_t i = 0; i < length; i++)
    printf("'%c'%s", array[i], (i == length - 1) ? "" : ", ");
  printf("}");
}

static void do_test(size_t n,
                    const char steve[n],
                    const char josh[n],
                    const char* expected) {
  char user_string[64];
  char* actual = game_outcome(n, steve, josh, user_string);
  printf("Steve's deck = ");
  print_array(n, steve);
  printf("\nJosh's deck  = ");
  print_array(n, josh);
  printf("\nExpected \"%s\", actual \"%s\"\n-> %s\n\n", expected, actual,
         strcmp(actual, expected) == 0 ? "OK" : "FAIL");
}

int main(void) {
  fixed_test(((char[]){'A', '7', '8'}), ((char[]){'K', '5', '9'}),
             "Steve wins 2 to 1");
  fixed_test(((char[]){'T', '9'}), ((char[]){'T', '8'}), "Steve wins 1 to 0");
  fixed_test(((char[]){'T'}), ((char[]){'T'}), "Tie");
  fixed_test(((char[]){'K', '2', '4', '5', '4', '3', '2', 'K', 'A', 'T'}),
             ((char[]){'Q', '3', '4', '6', '4', '3', '5', 'A', '8', '7'}),
             "Josh wins 4 to 3");
  fixed_test(((char[]){'A', 'K', '2', '3', 'A', '8', '5', '5', '7', 'T'}),
             ((char[]){'K', 'A', '5', '9', 'A', '3', '2', '6', '3', 'T'}),
             "Tie");
  fixed_test(((char[]){'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J',
                       'Q', 'K', 'A', '5', '6', '8', 'T', '3', 'T', 'J'}),
             ((char[]){'A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5',
                       '4', '3', '2', '2', '2', 'T', 'T', '9', '4', '3'}),
             "Steve wins 10 to 8");
  return 0;
}
