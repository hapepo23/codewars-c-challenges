/*
6 kyu
String searching with wildcard
https://www.codewars.com/kata/546c7f89bed2e12fb300056f
*/

#include <stdio.h>

long long find(const char* needle, const char* haystack);

static void do_test(const char* needle,
                    const char* haystack,
                    long long expected) {
  const long long actual = find(needle, haystack);
  printf(
      "Expected %lld, but got %lld\nfor needle   = \"%s\"\nand haystack = "
      "\"%s\"\n-> %s\n\n",
      expected, actual, needle, haystack, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  const char* const haystack =
      "Once upon a midnight dreary, while I pondered, weak and weary";
  do_test("abc", "___", -1);
  do_test("___", "abc", 0);
  do_test("a___b", "aaa___bbb", 2);
  do_test("Once", haystack, 0);
  do_test("midnight", haystack, 12);
  do_test("codewars", haystack, -1);
  do_test("_po_", haystack, 5);
  do_test("___night", haystack, 12);
  do_test("_", haystack, 0);
  do_test("", haystack, 0);
  do_test("", "", 0);
  do_test("____________________________________________________________",
          haystack, 0);
  do_test("_____________________________________________________________",
          haystack, 0);
  do_test("______________________________________________________________",
          haystack, -1);
  do_test(haystack, haystack, 0);
  return 0;
}
