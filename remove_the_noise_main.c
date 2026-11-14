/*
7 kyu
Remove the noise from the string
https://www.codewars.com/kata/5681cf0be812b41721000034
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_noise(char* input);

static void do_test(const char* input, const char* expected) {
  extern char* strdup(const char*);
  char* const actual = strdup(input);
  remove_noise(actual);
  printf("Input    = \"%s\"\nexpected = \"%s\"\nactual   = \"%s\"\n-> %s\n\n",
         input, expected, actual,
         strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test(u8"|⅋#⛜º#鲴☫#⛢C#&#·", u8"⅋⛜鲴☫⛢C");
  do_test(u8"|😱ȘȬ⚦·🙀$%", u8"😱ȘȬ⚦🙀");
  do_test(u8"%$&/#·@|º\\ª", u8"");
  do_test(u8"", u8"");
  do_test(u8"h%e&·%$·llo w&%or&$l·$%d", u8"hello world");
  do_test(u8"he%$·ll@o c$&%odi%&ng for ev|#·ery&$$#$on%$·e",
          u8"hello coding for everyone");
  do_test(u8"c|o@$%de%w@a·$r%s &rºocªks", u8"codewars rocks");
  return 0;
}
