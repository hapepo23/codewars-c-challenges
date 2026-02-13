/*
4 kyu
Ranking Poker Hands
https://www.codewars.com/kata/5739174624fc28e188000465
*/

#include <stdlib.h>
#include <string.h>

typedef enum {
  HIGH_CARD = 1,
  ONE_PAIR,
  TWO_PAIR,
  THREE_KIND,
  STRAIGHT,
  FLUSH,
  FULL_HOUSE,
  FOUR_KIND,
  STRAIGHT_FLUSH
} HandRank;

typedef struct Card {
  int rank;   // 2–14
  char suit;  // H D C S
} Card;

typedef struct HandValue {
  HandRank rank;
  int tiebreak[5];
} HandValue;

typedef struct Hand {
  Card cards[5];
  int num_cards;
} Hand;

typedef enum { Win, Loss, Tie } Result;

Hand* PokerHand(const char* cards) {
  Hand* hand = (Hand*)malloc(sizeof(Hand));
  int l = strlen(cards);
  hand->num_cards = (l + 1) / 3;
  for (int j = 0; j < hand->num_cards; j++) {
    int i = j * 3;
    hand->cards[j].suit = cards[i + 1];
    switch (cards[i]) {
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        hand->cards[j].rank = cards[i] - '0';
        break;
      case 'T':
        hand->cards[j].rank = 10;
        break;
      case 'J':
        hand->cards[j].rank = 11;
        break;
      case 'Q':
        hand->cards[j].rank = 12;
        break;
      case 'K':
        hand->cards[j].rank = 13;
        break;
      case 'A':
        hand->cards[j].rank = 14;
        break;
    }
  }
  return hand;
}

static int cmp_desc(const void* a, const void* b) {
  return (*(int*)b - *(int*)a);
}

static int is_flush(Card h[5]) {
  for (int i = 1; i < 5; i++)
    if (h[i].suit != h[0].suit)
      return 0;
  return 1;
}

static int is_straight(int r[5]) {
  if (r[0] == 14 && r[1] == 5 && r[2] == 4 && r[3] == 3 && r[4] == 2)
    return 5;
  for (int i = 0; i < 4; i++)
    if (r[i] - 1 != r[i + 1])
      return 0;
  return r[0];
}

static HandValue evaluate(Card h[], int n) {
  HandValue v = {0};
  int cnt[15] = {0};
  int r[5];
  for (int i = 0; i < n; i++) {
    r[i] = h[i].rank;
    cnt[r[i]]++;
  }
  qsort(r, n, sizeof(int), cmp_desc);
  int four = 0, three = 0, pairs[2] = {0}, p = 0;
  for (int i = 14; i >= 2; i--) {
    if (cnt[i] == 4)
      four = i;
    else if (cnt[i] == 3)
      three = i;
    else if (cnt[i] == 2)
      pairs[p++] = i;
  }
  if (four) {
    v.rank = FOUR_KIND;
    v.tiebreak[0] = four;
    for (int i = 0; i < n; i++)
      if (r[i] != four)
        v.tiebreak[1] = r[i];
    return v;
  }
  if (three && p) {
    v.rank = FULL_HOUSE;
    v.tiebreak[0] = three;
    v.tiebreak[1] = pairs[0];
    return v;
  }
  if (n == 5 && is_flush(h) && is_straight(r)) {
    v.rank = STRAIGHT_FLUSH;
    v.tiebreak[0] = is_straight(r);
    return v;
  }
  if (n == 5 && is_flush(h)) {
    v.rank = FLUSH;
    memcpy(v.tiebreak, r, n * sizeof(int));
    return v;
  }
  if (n == 5 && is_straight(r)) {
    v.rank = STRAIGHT;
    v.tiebreak[0] = is_straight(r);
    return v;
  }
  if (three) {
    v.rank = THREE_KIND;
    v.tiebreak[0] = three;
    int k = 1;
    for (int i = 0; i < n; i++)
      if (r[i] != three)
        v.tiebreak[k++] = r[i];
    return v;
  }
  if (p == 2) {
    v.rank = TWO_PAIR;
    v.tiebreak[0] = pairs[0];
    v.tiebreak[1] = pairs[1];
    for (int i = 0; i < n; i++)
      if (r[i] != pairs[0] && r[i] != pairs[1])
        v.tiebreak[2] = r[i];
    return v;
  }
  if (p == 1) {
    v.rank = ONE_PAIR;
    v.tiebreak[0] = pairs[0];
    int k = 1;
    for (int i = 0; i < n; i++)
      if (r[i] != pairs[0])
        v.tiebreak[k++] = r[i];
    return v;
  }
  v.rank = HIGH_CARD;
  memcpy(v.tiebreak, r, n * sizeof(int));
  return v;
}

Result compare(Hand* player, Hand* opponent) {
  Result r = Tie;
  HandValue A = evaluate(player->cards, player->num_cards);
  HandValue B = evaluate(opponent->cards, opponent->num_cards);
  if (A.rank != B.rank) {
    r = A.rank > B.rank ? Win : Loss;
  } else {
    for (int i = 0; i < 5; i++) {
      if (A.tiebreak[i] != B.tiebreak[i]) {
        r = A.tiebreak[i] > B.tiebreak[i] ? Win : Loss;
        break;
      }
    }
  }
  return r;
}
