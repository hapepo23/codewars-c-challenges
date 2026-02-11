/*
6 kyu
Find The Parity Outlier
https://www.codewars.com/kata/5526fc09a1bbd946250002dc
*/

#include <stddef.h>

#define FIND_PARITY_OUTLIER(OP)          \
  {                                      \
    for (size_t i = 0; i < count; i++) { \
      if (values[i] % 2 OP)              \
        return values[i];                \
    }                                    \
  }

int find_outlier(const int values[], size_t count) {
  int cnt[2] = {0, 0};
  for (size_t i = 0; i < 3; i++) {
    values[i] % 2 == 0 ? cnt[0]++ : cnt[1]++;
  }
  if (cnt[0] > cnt[1])
    FIND_PARITY_OUTLIER(!= 0)
  else
    FIND_PARITY_OUTLIER(== 0)
  return 0;  // should not happen
}
