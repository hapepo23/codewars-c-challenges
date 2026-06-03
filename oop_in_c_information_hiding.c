/*
6 kyu
Can You OOP in C? - Information Hiding
https://www.codewars.com/kata/5a2b86ce1f7f7052b800006d
*/

#include <stdlib.h>

typedef struct _array_minmax_t {
  int mini;
  int maxi;
} array_minmax_t;

void array_minmax_add(array_minmax_t* array, int number);

array_minmax_t* array_minmax_create(unsigned int length, int* input_array) {
  array_minmax_t* array = malloc(sizeof(array_minmax_t));
  array->mini = input_array[0];
  array->maxi = input_array[0];
  for (unsigned int i = 1; i < length; i++)
    array_minmax_add(array, input_array[i]);
  return array;
}

void array_minmax_add(array_minmax_t* array, int number) {
  if (number > array->maxi)
    array->maxi = number;
  if (number < array->mini)
    array->mini = number;
}

int array_minmax_get_min(array_minmax_t* array) {
  return array->mini;
}

int array_minmax_get_max(array_minmax_t* array) {
  return array->maxi;
}

void array_minmax_destroy(array_minmax_t* array) {
  free(array);
}
