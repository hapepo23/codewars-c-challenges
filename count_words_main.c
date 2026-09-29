/*
6 kyu
Count words
https://www.codewars.com/kata/56b3b27cadd4ad275500000c
*/

#include <stddef.h>
#include <stdio.h>

size_t count_words(const char* string);

static void do_test(const char* input, size_t expected) {
  size_t actual = count_words(input);
  printf("For string = \"%s\" ...\nExpected = %zu\nActual   = %zu\n-> %s\n\n",
         input, expected, actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("", 0);
  do_test("   ", 0);
  do_test("  888  ", 0);
  do_test(" A The On At Of Upon In As ", 0);
  do_test("   atheon atof  uponin  inas", 4);
  do_test("888abcde888efg666", 2);
  do_test("@@@word@@@word", 2);
  do_test("hello there", 2);
  do_test("hello there and a hi", 4);
  do_test("I'd like to say goodbye", 6);
  do_test("Slow-moving user6463 has been here", 6);
  do_test("%^&abc!@# wer45tre", 3);
  do_test("abc123abc123abc", 3);
  do_test("Really2374239847 long ^&#$&(*@# sequence", 3);
  do_test(
      "I'd been using my sphere as a stool. I traced counterclockwise circles "
      "on it"
      " with my fingertips and it shrank until I could palm it. My bolt had "
      "shifted"
      " while I'd been sitting. I pulled it up and yanked the pleats straight "
      "as I careered"
      " around tables, chairs, globes, and slow-moving fraas. I passed under a "
      "stone arch"
      " into the Scriptorium. The place smelled richly of ink. Maybe it was "
      "because an"
      " ancient fraa and his two fids were copying out books there. But I "
      "wondered"
      " how long it would take to stop smelling that way if no one ever used "
      "it at all;"
      " a lot of ink had been spent there, and the wet smell of it must be "
      "deep into everything.",
      112);
  return 0;
}
