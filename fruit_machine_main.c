/*
6 kyu
Fruit Machine
https://www.codewars.com/kata/590adadea658017d90000039
*/

#include <stdio.h>

unsigned fruit(const char* const* const reels[3], const unsigned spins[3]);

enum { ROWS = 3, COLS = 10 };

static void printReels(const char* const* const reels[ROWS]) {
  printf("{ ");
  for (int row = 0; row < ROWS; row++) {
    printf("\n { ");
    for (int col = 0; col < COLS; col++)
      printf("%d=\"%s\"%s", col, reels[row][col],
             (col == COLS - 1) ? "" : ", ");
    printf(" }%s", (row == ROWS - 1) ? "\n" : ",");
  }
  printf("}");
}

static void doTest(const char* const* const reels[ROWS],
                   const unsigned spins[ROWS],
                   unsigned expected) {
  unsigned actual = fruit(reels, spins);
  printf("Reels = ");
  printReels(reels);
  printf("\n");
  printf("Spins = { %u, %u, %u }\nExpected = %u, Received = %u\n-> %s\n\n",
         spins[0], spins[1], spins[2], expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  {
    const char* const* reels[3] = {
        (const char* [10]){"Wild", "Star", "Bell", "Shell", "Seven", "Cherry",
                           "Bar", "King", "Queen", "Jack"},
        (const char* [10]){"Wild", "Star", "Bell", "Shell", "Seven", "Cherry",
                           "Bar", "King", "Queen", "Jack"},
        (const char* [10]){"Wild", "Star", "Bell", "Shell", "Seven", "Cherry",
                           "Bar", "King", "Queen", "Jack"}};
    doTest(reels, (unsigned[3]){0, 0, 0}, 100);
  }
  {
    const char* const* reels[3] = {
        (const char* [10]){"Wild", "Star", "Bell", "Shell", "Seven", "Cherry",
                           "Bar", "King", "Queen", "Jack"},
        (const char* [10]){"Bar", "Wild", "Queen", "Bell", "King", "Seven",
                           "Cherry", "Jack", "Star", "Shell"},
        (const char* [10]){"Bell", "King", "Wild", "Bar", "Seven", "Jack",
                           "Shell", "Cherry", "Queen", "Star"}};
    doTest(reels, (unsigned[3]){5, 4, 3}, 0);
  }
  {
    const char* const* reels[3] = {
        (const char* [10]){"King", "Cherry", "Bar", "Jack", "Seven", "Queen",
                           "Star", "Shell", "Bell", "Wild"},
        (const char* [10]){"Bell", "Seven", "Jack", "Queen", "Bar", "Star",
                           "Shell", "Wild", "Cherry", "King"},
        (const char* [10]){"Wild", "King", "Queen", "Seven", "Star", "Bar",
                           "Shell", "Cherry", "Jack", "Bell"}};
    doTest(reels, (unsigned[3]){0, 0, 1}, 3);
  }
  {
    const char* const* reels[3] = {
        (const char* [10]){"King", "Jack", "Wild", "Bell", "Star", "Seven",
                           "Queen", "Cherry", "Shell", "Bar"},
        (const char* [10]){"Star", "Bar", "Jack", "Seven", "Queen", "Wild",
                           "King", "Bell", "Cherry", "Shell"},
        (const char* [10]){"King", "Bell", "Jack", "Shell", "Star", "Cherry",
                           "Queen", "Bar", "Wild", "Seven"}};
    doTest(reels, (unsigned[3]){0, 5, 0}, 6);
  }
  return 0;
}
