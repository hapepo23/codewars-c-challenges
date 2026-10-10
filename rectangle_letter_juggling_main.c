/*
6 kyu
Rectangle letter juggling
https://www.codewars.com/kata/60d6f2653cbec40007c92755
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encode(const char* plaintext);

static void do_test(const char* plaintext, const char* ciphertext) {
  char* const actual = encode(plaintext);
  printf("For string: \"%s\"\nexpected: \"%s\"\nactual  : \"%s\"\n-> %s\n\n",
         plaintext, ciphertext, actual,
         strcmp(ciphertext, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test(
      "When nobody is around, the trees gossip about the people who have "
      "walked under them.",
      "wytotear hihstwlt eseshhkh natieoee nrrpphdm ooeaeau  buebovn  onsoped  "
      "ddgulwe ");
  do_test("I want a giraffe, but I'm a turtle eating waffles.",
          "iiuril wrttne aailgs nfmew  tfaea  aetaf  gbutf ");
  do_test(
      "Dolores wouldn't have eaten the meal if she had known what it actually "
      "was.",
      "dovhsoty oueehwaw llemenca odaehwts rntaahu  eteldaa  shniktl  "
      "watfnil ");
  do_test("She says she has the ability to hear the soundtrack of your life.",
          "shaoscl hebhoki ehieuof salanfe asirdy  ytttto  shyhru  setear ");
  do_test("a", "a");
  do_test("ab", "a b");
  do_test("abc", "ac b ");
  do_test("abcd", "ac bd");
  do_test("", "");
  return 0;
}
