/*
7 kyu
Stalin Sort
https://www.codewars.com/kata/699af631058f5c12b04f4efe
*/

#include <stddef.h>
#include <stdio.h>

// ☭ The Party demands order. Provide it. ☭
// Hint: puts("Расстрелять!") for each eliminated element

void stalin_sort(size_t* length, int array[*length]) {
  size_t pos = 1;
  while (pos < *length) {
    if (array[pos] < array[pos - 1]) {
      puts("Расстрелять!");
      --(*length);
      for (size_t j = pos; j < *length; j++)
        array[j] = array[j + 1];
    } else
      ++pos;
  }
}
