/*
6 kyu
How many pages in a book?
https://www.codewars.com/kata/622de76d28bf330057cd6af8
*/

unsigned amount_of_pages(unsigned summary) {
  unsigned d = 1;
  unsigned s = 1;
  while (1) {
    unsigned b = 9 * s * d;
    if (summary <= b)
      return s - 1 + summary / d;
    summary -= b;
    d++;
    s *= 10;
  }
}
