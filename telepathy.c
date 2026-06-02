/*
6 kyu
Telepathy
https://www.codewars.com/kata/64ad571aa33413003e712168
*/

/*

Only 1 line of code and 150 characters of code can be used.

Solution:

unsigned magic_show(const char *ans) {int n=1, r=0; while (*ans) { if
(*ans=='Y') {r+= n; n*=2;} if (*ans=='N') n*=2; ans++;} return r;}

*/

unsigned magic_show(const char* ans) {
  int n = 1, r = 0;
  while (*ans) {
    if (*ans == 'Y') {
      r += n;
      n *= 2;
    }
    if (*ans == 'N')
      n *= 2;
    ans++;
  }
  return r;
}
