/*
7 kyu
Jaden Casing Strings
https://www.codewars.com/kata/5390bac347d09b7da40006f6
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* to_jaden_case(char* jaden_case, const char* string);

static void do_test(const char* input, const char* expected) {
  size_t mem_size = strlen(expected) + 1;
  char* user_string = memset(malloc(mem_size), '@', mem_size);
  char* actual = to_jaden_case(user_string, input);
  printf(
      "String  : \"%s\"\n"
      "Expected: \"%s\"\n"
      "Actual  : \"%s\"\n"
      "-> %s\n\n",
      input, expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(user_string);
}

int main(void) {
  do_test("", "");
  do_test("How can mirrors be real if our eyes aren't real",
          "How Can Mirrors Be Real If Our Eyes Aren't Real");
  do_test(
      "All the rules in this world were made by someone no smarter than you. "
      "So make your own.",
      "All The Rules In This World Were Made By Someone No Smarter Than You. "
      "So Make Your Own.");
  do_test("School is the tool to brainwash the youth.",
          "School Is The Tool To Brainwash The Youth.");
  do_test(
      "If everybody in the world dropped out of school we would have a much "
      "more intelligent society.",
      "If Everybody In The World Dropped Out Of School We Would Have A Much "
      "More Intelligent Society.");
  do_test("Dying is mainstream", "Dying Is Mainstream");
  do_test(
      "If there is bread winners, there is bread losers. But you can't toast "
      "what isn't real.",
      "If There Is Bread Winners, There Is Bread Losers. But You Can't Toast "
      "What Isn't Real.");
  do_test("When you Live your Whole life In a Prison freedom Can be So dull.",
          "When You Live Your Whole Life In A Prison Freedom Can Be So Dull.");
  do_test("The moment that truth is organized it becomes a lie.",
          "The Moment That Truth Is Organized It Becomes A Lie.");
  do_test(
      "Pay attention to the numbers in your life they are vastly important.",
      "Pay Attention To The Numbers In Your Life They Are Vastly Important.");
  do_test(
      "If a book store never runs out of a certain book, dose that mean that "
      "nobody reads it, or everybody reads it",
      "If A Book Store Never Runs Out Of A Certain Book, Dose That Mean That "
      "Nobody Reads It, Or Everybody Reads It");
  return 0;
}
