/*
5 kyu
Conway's Look and Say - Generalized
https://www.codewars.com/kata/530045e3c7c0f4d3420001af
*/

typedef unsigned long long ullong;

ullong look_say(ullong n) {
  static ullong ten = 10ULL;
  ullong result = 0ULL;
  ullong multiplier = 1ULL;
  do {
    ullong digit = n % ten;
    ullong count = 0ULL;
    do {
      count++;
      n /= ten;
    } while (n && n % ten == digit);
    result += digit * multiplier;
    multiplier *= ten;
    do {
      result += (count % ten) * multiplier;
      multiplier *= ten;
      count /= ten;
    } while (count);
  } while (n);
  return result;
}
