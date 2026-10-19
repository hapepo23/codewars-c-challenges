/*
6 kyu
Guess the number!
https://www.codewars.com/kata/5452113c699b538c18000b01
*/

enum Status { CORRECT, TOO_LOW, TOO_HIGH };

enum Status guess(int number);

int get_number(void) {
  int low = 1;
  int high = 1000;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    enum Status stat = guess(mid);
    if (stat == CORRECT)
      return mid;
    if (stat == TOO_HIGH)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return 0; /* should not happen */
}
