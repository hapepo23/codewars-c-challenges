/*
6 kyu
Canal Management
https://www.codewars.com/kata/61c1ffd793863e002c1e42b5
*/

#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))

#define fixed_test(lock_length, low_queue, high_queue, expected)           \
  do_test(lock_length, ARR_LEN(low_queue), low_queue, ARR_LEN(high_queue), \
          high_queue, expected)

unsigned manage_canal(unsigned lock_length,
                      size_t nb_low_boats,
                      const unsigned low_queue[nb_low_boats],
                      size_t nb_high_boats,
                      const unsigned high_queue[nb_high_boats]);

static void print_array(size_t length, const unsigned array[length]) {
  printf("{");
  for (size_t i = 0; i < length; i++)
    printf("%u%s", array[i], (i == length - 1) ? "" : ", ");
  printf("}");
}

static void do_test(unsigned lock_length,
                    size_t nb_low_boats,
                    const unsigned low_queue[nb_low_boats],
                    size_t nb_high_boats,
                    const unsigned high_queue[nb_high_boats],
                    unsigned expected) {
  unsigned actual = manage_canal(lock_length, nb_low_boats, low_queue,
                                 nb_high_boats, high_queue);
  printf("Low queue = ");
  print_array(nb_low_boats, low_queue);
  printf("\nHigh queue = ");
  print_array(nb_high_boats, high_queue);
  printf("\nLock length = %u\nExpected = %u, actual = %u -> %s\n\n",
         lock_length, expected, actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  fixed_test(7, ((unsigned[]){2, 3, 6, 1}), ((unsigned[]){1, 2}), 38);
  fixed_test(8, ((unsigned[]){4, 1, 8, 2, 6}), ((unsigned[]){}), 54);
  fixed_test(30,
             ((unsigned[]){1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
                           17, 18, 19, 20}),
             ((unsigned[]){20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
                           10, 9,  8,  7,  6,  5,  4,  3,  2,  1}),
             868);
  do_test(8, 0, NULL, 6, (unsigned[6]){4, 4, 7, 2, 8, 5}, 80);
  do_test(10, 0, NULL, 0, NULL, 0);
  return 0;
}
