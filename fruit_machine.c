/*
6 kyu
Fruit Machine
https://www.codewars.com/kata/590adadea658017d90000039
*/

#include <string.h>

enum { ROWS = 3, COLS = 10 };

unsigned fruit(const char* const* const reels[ROWS],
               const unsigned spins[ROWS]) {
  const char* rank[COLS] = {"Jack",  "Queen", "King", "Bar",  "Cherry",
                            "Seven", "Shell", "Bell", "Star", "Wild"};
  unsigned count[COLS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  const char* rspins[ROWS];
  for (unsigned i = 0; i < ROWS; i++) {
    rspins[i] = reels[i][spins[i]];
    for (unsigned j = 0; j < COLS; j++)
      if (strcmp(rspins[i], rank[j]) == 0) {
        count[j]++;
        break;
      }
  }
  for (unsigned j = 0; j < COLS; j++) {
    if (count[j] == 3)
      return (j + 1) * 10;
    else if (j < 9 && count[j] == 2 && count[9] == 1)
      return (j + 1) * 2;
    else if (count[j] == 2)
      return j + 1;
  }
  return 0;
}
