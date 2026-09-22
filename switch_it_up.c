/*
8 kyu
Switch it Up!
https://www.codewars.com/kata/5808dcb8f0ed42ae34000031
*/

static const char* digit_word[] = {"Zero", "One", "Two",   "Three", "Four",
                                   "Five", "Six", "Seven", "Eight", "Nine"};

const char* switchItUp(int digit) {
  return digit_word[digit];
}
