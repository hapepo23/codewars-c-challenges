/*
6 kyu
Two Sum
https://www.codewars.com/kata/52c31f8e6605bcc646000082
*/

#include <stdio.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))

void twoSum(unsigned count,
            const int numbers[count],
            int target,
            unsigned* index1,
            unsigned* index2);

static void printArray(size_t length, const int array[length]) {
  printf("{");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf("}\n");
}

static void doTest(unsigned count,
                   const int numbers[count],
                   const int expected[2]) {
  int target = numbers[expected[0]] + numbers[expected[1]];
  unsigned index1 = 666, index2 = 666;
  twoSum(count, numbers, target, &index1, &index2);
  printf("numbers array = ");
  printArray(count, numbers);
  int actual = numbers[index1] + numbers[index2];
  printf("numbers[%u] (%d) + numbers[%u] (%d) == %d, target was %d\n-> %s\n\n",
         index1, numbers[index1], index2, numbers[index2], actual, target,
         actual == target ? "OK" : "FAIL");
}

int main(void) {
  {
    int numbers[] = {2, 1, 3}, expected[] = {1, 2};
    doTest(ARR_LEN(numbers), numbers, expected);
  }
  {
    int numbers[] = {1, 2, 3}, expected[] = {0, 2};
    doTest(ARR_LEN(numbers), numbers, expected);
  }
  {
    int numbers[] = {1234, 5678, 9012}, expected[] = {1, 2};
    doTest(ARR_LEN(numbers), numbers, expected);
  }
  {
    int numbers[] = {2, 2, 3}, expected[] = {0, 1};
    doTest(ARR_LEN(numbers), numbers, expected);
  }
}
