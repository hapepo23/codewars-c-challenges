/*
5 kyu
Formula 1 Race
https://www.codewars.com/kata/626d691649cb3c7acd63457b
*/

#include <stdio.h>

static int ranks[20];
static int count;

static void reset(void) {
  count = 20;
  for (int i = 0; i < count; i++)
    ranks[i] = i + 1;
}

static void incident(int pilot) {
  for (int i = 0; i < count; i++) {
    if (ranks[i] == pilot) {
      for (int j = i; j < count - 1; j++)
        ranks[j] = ranks[j + 1];
      count--;
      return;
    }
  }
}

static void overtake(int pilot) {
  for (int i = 0; i < count; i++) {
    if (ranks[i] == pilot) {
      if (i > 0) {
        int temp = ranks[i - 1];
        ranks[i - 1] = ranks[i];
        ranks[i] = temp;
      }
      return;
    }
  }
}

static int getrank(int pilot) {
  for (int i = 0; i < count; i++)
    if (ranks[i] == pilot)
      return i + 1;
  return -1;
}

int champion_rank(int champion_ID, const char* events) {
  int pos = 0, n, c, pilot;
  char code;
  reset();
  while (1) {
    n = sscanf(events + pos, "%d %c%n", &pilot, &code, &c);
    if (n < 2)
      break;
    pos += c;
    switch (code) {
      case 'I':
        if (pilot == champion_ID)
          return -1;
        incident(pilot);
        break;
      case 'O':
        overtake(pilot);
        break;
    }
  }
  return getrank(champion_ID);
}
