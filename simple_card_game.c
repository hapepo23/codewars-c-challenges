/*
6 kyu
Simple card game
https://www.codewars.com/kata/53417de006654f4171000587
*/

#include <stdio.h>

unsigned cardvalue(const char card) {
  switch (card) {
    case 'A':
      return 14;
    case 'K':
      return 13;
    case 'Q':
      return 12;
    case 'J':
      return 11;
    case 'T':
      return 10;
    default:
      return (unsigned)(card - '0');
  }
}

char* game_outcome(size_t n,
                   const char steve[n],
                   const char josh[n],
                   char* outcome) {
  unsigned stevecnt = 0;
  unsigned joshcnt = 0;
  for (size_t i = 0; i < n; i++) {
    unsigned steveval = cardvalue(steve[i]);
    unsigned joshval = cardvalue(josh[i]);
    if (steveval > joshval)
      stevecnt++;
    else if (joshval > steveval)
      joshcnt++;
  }
  if (stevecnt > joshcnt)
    sprintf(outcome, "Steve wins %u to %u", stevecnt, joshcnt);
  else if (stevecnt == joshcnt)
    sprintf(outcome, "Tie");
  else
    sprintf(outcome, "Josh wins %u to %u", joshcnt, stevecnt);
  return outcome;
}
