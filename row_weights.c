/*
7 kyu
Row Weights
https://www.codewars.com/kata/5abd66a5ccfd1130b30000a9
*/

void rowWeights(const int weights[], int count, int teams[]) {
  teams[0] = 0;
  teams[1] = 0;
  for (int i = 0; i < count; i += 2) {
    teams[0] += weights[i];
    if (i + 1 < count)
      teams[1] += weights[i + 1];
  }
}
