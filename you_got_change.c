/*
7 kyu
You Got Change?
https://www.codewars.com/kata/5966f6343c0702d1dc00004c
*/

void give_change(unsigned amount, unsigned bills[6]) {
  static const unsigned billvalues[6] = {1, 5, 10, 20, 50, 100};
  for (unsigned i = 6; i-- > 0;) {
    bills[i] = amount / billvalues[i];
    amount %= billvalues[i];
  }
}
