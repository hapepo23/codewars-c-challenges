/*
6 kyu
The Supermarket Queue
https://www.codewars.com/kata/57b06f90e298a7b53d000a86
*/

#include <stdio.h>
#include <stdlib.h>

int queue_time(const int customers[], int customers_length, int n);

static char* sprint_array(size_t len, const int array[len]) {
  enum { INT_LEN = sizeof "-9223372036854775808, " - 1 };
  char *const str = malloc(len * INT_LEN + sizeof "{  }"), *ptr = str;
  ptr += sprintf(ptr, "{");
  for (size_t i = 0; i < len; i++)
    ptr += sprintf(ptr, "%d%s", array[i], (i == len - 1) ? "" : ", ");
  ptr += sprintf(ptr, "}");
  return str;
}

static void test_queue_time(size_t len,
                            const int customers[len],
                            int n,
                            int expected) {
  char* customers_str = sprint_array(len, customers);
  int actual = queue_time(customers, len, n);
  printf("Queue_time(%s, %zu, %d) should return %d, actual: %d -> %s\n",
         customers_str, len, n, expected, actual,
         actual == expected ? "OK" : "FAIL");
  free(customers_str);
}

int main(void) {
  test_queue_time(0, NULL, 1, 0);
  test_queue_time(4, (int[4]){1, 2, 3, 4}, 1, 10);
  test_queue_time(1, (int[1]){5}, 1, 5);
  test_queue_time(1, (int[1]){2}, 5, 2);
  test_queue_time(5, (int[5]){1, 2, 3, 4, 5}, 1, 15);
  test_queue_time(6, (int[6]){2, 2, 3, 3, 4, 4}, 2, 9);
  test_queue_time(5, (int[5]){1, 2, 3, 4, 5}, 100, 5);
  return 0;
}
