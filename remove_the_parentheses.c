/*
6 kyu
Remove the parentheses
https://www.codewars.com/kata/5f7c38eb54307c002a2b8cc8
*/

void remove_parentheses(const char* str_in, char* str_out) {
  const char* in = str_in;
  char* out = str_out;
  unsigned parcnt = 0;
  while (*in) {
    if (*in == '(')
      parcnt++;
    else if (*in == ')')
      parcnt--;
    else if (!parcnt)
      *(out++) = *in;
    in++;
  }
  *out = '\0';
}
