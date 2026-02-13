/*
4 kyu
Ranking Poker Hands
https://www.codewars.com/kata/5739174624fc28e188000465
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Hand Hand;
typedef enum { Win, Loss, Tie } Result;

Hand* PokerHand(const char* cards);
Result compare(Hand* player, Hand* opponent);

void run_test(const char* player,
              const char* opponent,
              Result outcome,
              const char* text) {
  Hand* p = PokerHand(player);
  Hand* o = PokerHand(opponent);
  Result result = compare(p, o);
  free(p);
  free(o);
  printf("Player: %s, Opponent: %s, Expected: %s, Actual: %s --> %s (%s)\n",
         player, opponent,
         outcome == Win ? "Win" : (outcome == Loss ? "Loss" : "Tie"),
         result == Win ? "Win" : (result == Loss ? "Loss" : "Tie"),
         result == outcome ? "OK" : "FAIL", text);
}

int main(void) {
  run_test("2H 3H 4H 5H 6H", "KS AS TS QS JS", Loss,
           "Highest straight flush wins");
  run_test("2H 3H 4H 5H 6H", "AS AD AC AH JD", Win,
           "Straight flush wins of 4 of a kind");
  run_test("AS AH 2H AD AC", "JS JD JC JH 3D", Win, "Highest 4 of a kind wins");
  run_test("2S AH 2H AS AC", "JS JD JC JH AD", Loss,
           "4 Of a kind wins of full house");
  run_test("2S AH 2H AS AC", "2H 3H 5H 6H 7H", Win, "Full house wins of flush");
  run_test("AS 3S 4S 8S 2S", "2H 3H 5H 6H 7H", Win, "Highest flush wins");
  run_test("2H 3H 5H 6H 7H", "2S 3H 4H 5S 6C", Win, "Flush wins of straight");
  run_test("2S 3H 4H 5S 6C", "3D 4C 5H 6H 2S", Tie, "Equal straight is tie");
  run_test("2S 3H 4H 5S 6C", "AH AC 5H 6H AS", Win,
           "Straight wins of three of a kind");
  run_test("2S 3H 4H 5S AC", "AH AC 5H 6H AS", Win,
           "Low-ace straight wins of three of a kind");
  run_test("2S 2H 4H 5S 4C", "AH AC 5H 6H AS", Loss,
           "3 Of a kind wins of two pair");
  run_test("2S 2H 4H 5S 4C", "AH AC 5H 6H 7S", Win, "2 Pair wins of pair");
  run_test("6S AD 7H 4S AS", "AH AC 5H 6H 7S", Loss, "Highest pair wins");
  run_test("2S AH 4H 5S KC", "AH AC 5H 6H 7S", Loss, "Pair wins of nothing");
  run_test("2S 3H 6H 7S 9C", "7H 3C TH 6H 9S", Loss, "Highest card loses");
  run_test("4S 5H 6H TS AC", "3S 5H 6H TS AC", Win, "Highest card wins");
  run_test("2S AH 4H 5S 6C", "AD 4C 5H 6H 2C", Tie, "Equal cards is tie");
  run_test("JC 6H JS JD JH", "JC 7H JS JD JH", Loss, "Highest card wins");
  return 0;
}
