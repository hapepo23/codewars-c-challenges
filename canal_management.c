/*
6 kyu
Canal Management
https://www.codewars.com/kata/61c1ffd793863e002c1e42b5
*/

#include <stddef.h>

unsigned manage_canal(unsigned lock_length,
                      size_t nb_low_boats,
                      const unsigned low_queue[nb_low_boats],
                      size_t nb_high_boats,
                      const unsigned high_queue[nb_high_boats]) {
  size_t pos_low = 0, pos_high = 0;
  unsigned result = 0;
  while (pos_low < nb_low_boats || pos_high < nb_high_boats) {
    unsigned len = 0;
    for (; pos_low < nb_low_boats; pos_low++) {
      if (len + low_queue[pos_low] > lock_length)
        break;
      len += low_queue[pos_low];
    }
    result += len * 2 + 2;
    len = 0;
    for (; pos_high < nb_high_boats; pos_high++) {
      if (len + high_queue[pos_high] > lock_length)
        break;
      len += high_queue[pos_high];
    }
    result += len * 2 + 2;
  }
  return result;
}
