/*
6 kyu
Evaluate the Group of Parentheses
https://www.codewars.com/kata/64b6722493f1050058dc3f98
*/

int parentheses_score(const char* parentheses) {
  int score = 0;
  int depth = 0;
  for (int i = 0; parentheses[i] != '\0'; i++) {
    if (parentheses[i] == '(') {
      depth++;
    } else {
      depth--;
      if (i > 0 && parentheses[i - 1] == '(') {
        score += 1 << depth;
      }
    }
  }
  return score;
}
