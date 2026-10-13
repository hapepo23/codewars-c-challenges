/*
6 kyu
Sum of a Sequence [Hard-Core Version]
https://www.codewars.com/kata/587a88a208236efe8500008b
*/

typedef long long int lli;

lli sequence_sum(lli begin_number, lli end_number, lli step) {
  if (begin_number == end_number)
    return begin_number;
  if ((begin_number < end_number && step < 0) ||
      (begin_number > end_number && step > 0))
    return 0;
  lli n = (end_number - begin_number) / step + 1;
  return n * (2 * begin_number + (n - 1) * step) / 2;
}
