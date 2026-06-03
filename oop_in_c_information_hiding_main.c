/*
6 kyu
Can You OOP in C? - Information Hiding
https://www.codewars.com/kata/5a2b86ce1f7f7052b800006d
*/

// Start of array_minmax.h
struct _array_minmax_t;
typedef struct _array_minmax_t array_minmax_t;

array_minmax_t* array_minmax_create(unsigned int length, int* input_array);

// Add a number to the array
void array_minmax_add(array_minmax_t* array, int number);

// Get min/max value of the array
int array_minmax_get_min(array_minmax_t* array);
int array_minmax_get_max(array_minmax_t* array);

// Destructor
void array_minmax_destroy(array_minmax_t* array);

// End of array_minmax.h

#include <stdio.h>

static array_minmax_t* array;
static int input_array[5] = {4, 2, 9, 7, 1};

static void do_test(int actual, int expected, char* msg) {
  if (actual == expected)
    puts("-> OK");
  else
    printf("-> FAIL ... %d = %s, must be %d\n", actual, msg, expected);
}

int main(void) {
  array = array_minmax_create(5, input_array);
  do_test(array_minmax_get_min(array), 1, "Incorrect minimum value");
  do_test(array_minmax_get_max(array), 9, "Incorrect maximum value");
  array_minmax_add(array, 3);
  do_test(array_minmax_get_min(array), 1, "Incorrect minimum value");
  do_test(array_minmax_get_max(array), 9, "Incorrect maximum value");
  array_minmax_add(array, 200);
  do_test(array_minmax_get_min(array), 1, "Incorrect minimum value");
  do_test(array_minmax_get_max(array), 200, "Incorrect maximum value");
  array_minmax_add(array, -99);
  do_test(array_minmax_get_min(array), -99, "Incorrect minimum value");
  do_test(array_minmax_get_max(array), 200, "Incorrect maximum value");
  array_minmax_destroy(array);
  return 0;
}
