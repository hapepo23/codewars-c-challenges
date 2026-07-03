/*
5 kyu
First Variation on Caesar Cipher
https://www.codewars.com/kata/5508249a98b3234f420000fb
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** movingShift(const char* s, int shift);
char* demovingShift(const char* const s[5], int shift);

static char* stringsRepr(size_t length, const char* const strings[length]) {
  size_t size = sizeof("{}") + length * (sizeof("\"\", ") - 1);
  for (size_t i = 0; i < length; i++)
    size += strlen(strings[i]);
  char *repr = malloc(size), *ptr = repr;
  ptr += sprintf(ptr, "{");
  for (size_t i = 0; i < length; i++)
    ptr += sprintf(ptr, "\"%s\"%s", strings[i], (i == length - 1) ? "" : ", ");
  ptr += sprintf(ptr, "}");
  return repr;
}

static void testMoving(const char* string,
                       int shift,
                       const char* const expected[5]) {
  char** actual = movingShift(string, shift);
  bool equal = true;
  for (int i = 0; i < 5; i++)
    equal &= !strcmp(actual[i], expected[i]);
  char* repr_actual = stringsRepr(5, (const char**)actual);
  char* repr_expected = stringsRepr(5, expected);
  printf(
      "Moving:\nfor shift = %d and string = \"%s\"\nexpected: %s\nactual  : "
      "%s\n-> %s\n\n",
      shift, string, repr_expected, repr_actual, equal ? "OK" : "FAIL");
  free(repr_actual);
  free(repr_expected);
  for (int i = 0; i < 5; i++)
    free(actual[i]);
  free(actual);
}

static void testDemoving(const char* const strings[5],
                         int shift,
                         const char* expected) {
  char* actual = demovingShift(strings, shift);
  char* repr = stringsRepr(5, strings);
  printf(
      "Demoving:\nfor shift = %d and strings = %s\nexpected: \"%s\"\nactual  : "
      "\"%s\"\n->%s\n\n",
      shift, repr, expected, actual,
      strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(repr);
  free(actual);
}

int main(void) {
  {
    char* u =
        "I-should-have-known-that-you-would-have-a-perfect-answer-for-me!!!";
    const char* d[5] = {"J-vltasl-rlhr-", "zdfog-odxr-ypw", "-atasl-rlhr-p-",
                        "gwkzzyq-zntyhv", "-lvz-wp!!!"};
    testMoving(u, 1, d);
    testDemoving(d, 1, u);
  }
  {
    char* u = "-uoxIirmoveNreefckgieaoiEcooqo";
    const char* d[5] = {"-xscOp", "zvygqA", "ftuwud", "adaxmh", "Edqrut"};
    testMoving(u, 2, d);
    testDemoving(d, 2, u);
  }
  {
    char* u = "O-CAPTAIN!-my-Captain!-our-fearful-trip-is-done;";
    const char* d[5] = {"Q-GFVAIRX!", "-zm-Srhmud", "j!-nus-iif", "xmcu-edvd-",
                        "yj-wiia;"};
    testMoving(u, 2, d);
    testDemoving(d, 2, u);
  }
  {
    char* u = "Every-decision-that-we-make-leads-us-down-a-different-road.";
    const char* d[5] = {"Fxhvd-kmlsdu", "bb-jysm-ra-k", "zkf-oifjz-dc",
                        "-pbkc-r-wcab", "bpdnu-usfj."};
    testMoving(u, 1, d);
    testDemoving(d, 1, u);
  }
  {
    char* u =
        "How-can-we-become-the-kind-of-people-that-face-our-fear-and-do-it-"
        "anyway?";
    const char* d[5] = {"Iqz-hgu-fo-nrqd", "cv-mbz-hgmd-qi-", "ukvxuo-fuoi-wsv",
                        "y-krp-ffcu-ftk-", "my-ug-pdpots?"};
    testMoving(u, 1, d);
    testDemoving(d, 1, u);
  }
  {
    char* u = "uaoQop-jx-eh-osr-okaKv-vzagzwpxagokBKriipmc-U";
    const char* d[5] = {"vcrUtv-rg", "-pt-chh-g", "duFr-tyah", "bztcgnwtL",
                        "Vdvwect-N"};
    testMoving(u, 1, d);
    testDemoving(d, 1, u);
  }
  {
    char* u = "uaoQop-jx-eh-osr-okaKv-vzagzwpxagokBKriipmc-U";
    const char* d[5] = {"wdsVuw-sh", "-qu-dii-h", "evGs-uzbi", "caudhoxuM",
                        "Wewxfdu-O"};
    testMoving(u, 2, d);
    testDemoving(d, 2, u);
  }
  {
    char* u = "I can reset";
    const char* d[5] = {"L h", "gu ", "aod", "qg", ""};
    testMoving(u, 3, d);
    testDemoving(d, 3, u);
  }
  {
    char* u = "I";
    const char* d[5] = {"L", "", "", "", ""};
    testMoving(u, 3, d);
    testDemoving(d, 3, u);
  }
  return 0;
}
