/*
6 kyu
Equal Sides Of An Array
https://www.codewars.com/kata/5679aa472b8f57fb8c000047
*/

#include <stdio.h>

int find_even_index(const int* values, int length);

int main(void) {
  {
    int arr[] = {1, 2, 3, 4, 3, 2, 1};
    int expected = 3;
    int result = find_even_index(arr, (int)(sizeof(arr) / sizeof(arr[0])));
    printf("Expected: %d. Received: %d.\n", expected, result);
  }
  {
    int arr[] = {1, 100, 50, -51, 1, 1};
    int expected = 1;
    int result = find_even_index(arr, (int)(sizeof(arr) / sizeof(arr[0])));
    printf("Expected: %d. Received: %d.\n", expected, result);
  }
  {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int expected = -1;
    int result = find_even_index(arr, (int)(sizeof(arr) / sizeof(arr[0])));
    printf("Expected: %d. Received: %d.\n", expected, result);
  }
  {
    int arr[] = {20, 10, 30, 10, 10, 15, 35};
    int expected = 3;
    int result = find_even_index(arr, (int)(sizeof(arr) / sizeof(arr[0])));
    printf("Expected: %d. Received: %d.\n", expected, result);
  }
  {
    int arr[] = {20, 10, -80, 10, 10, 15, 35};
    int expected = 0;
    int result = find_even_index(arr, (int)(sizeof(arr) / sizeof(arr[0])));
    printf("Expected: %d. Received: %d.\n", expected, result);
  }
  {
    int arr[] = {10, -80, 10, 10, 15, 35, 20};
    int expected = 6;
    int result = find_even_index(arr, (int)(sizeof(arr) / sizeof(arr[0])));
    printf("Expected: %d. Received: %d.\n", expected, result);
  }
  {
    int arr[] = {0, 0, 0, 0, 0};
    int expected = 0;
    int result = find_even_index(arr, (int)(sizeof(arr) / sizeof(arr[0])));
    printf("Expected: %d. Received: %d.\n", expected, result);
  }
  {
    int arr[] = {-1, -2, -3, -4, -3, -2, -1};
    int expected = 3;
    int result = find_even_index(arr, (int)(sizeof(arr) / sizeof(arr[0])));
    printf("Expected: %d. Received: %d.\n", expected, result);
  }
  return 0;
}