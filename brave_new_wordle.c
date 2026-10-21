/*
5 kyu
A Brave New Wordle
https://www.codewars.com/kata/62013b174c72240016600e60
*/

void wordle(char hints[6], const char guess[6], const char solution[6]) {
  int used[5] = {0};
  /* First pass: mark green letters */
  for (int i = 0; i < 5; i++) {
    if (guess[i] == solution[i]) {
      hints[i] = 'g';
      used[i] = 1;
    } else {
      hints[i] = 'b';
    }
  }
  /* Second pass: mark yellow letters, left to right */
  for (int i = 0; i < 5; i++) {
    if (hints[i] == 'g')
      continue;
    for (int j = 0; j < 5; j++) {
      if (!used[j] && guess[i] == solution[j]) {
        hints[i] = 'y';
        used[j] = 1;
        break;
      }
    }
  }
  hints[5] = '\0';
}
