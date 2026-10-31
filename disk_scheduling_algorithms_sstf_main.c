/*
7 kyu
Disk scheduling algorithms: SSTF
https://www.codewars.com/kata/63e50629be9fe90024f3a749
*/

#include <stdio.h>

unsigned sstf(size_t length,
              const unsigned request_queue[length],
              unsigned initial_head_position);

static char* stringer(size_t length,
                      const unsigned array[length],
                      char* arr_str) {
  size_t index = 0, pos = sprintf(arr_str, "{");
  while (index < length) {
    pos += sprintf(arr_str + pos, "%u%s", array[index],
                   (index == length - 1) ? "" : ", ");
    index++;
  }
  sprintf(arr_str + pos, "}");
  return arr_str;
}

static void tester(size_t length,
                   const unsigned request_queue[length],
                   unsigned initial_head_position,
                   unsigned expected) {
  unsigned submitted = sstf(length, request_queue, initial_head_position);
  char req_str[230 * length + 3];
  printf(
      "Request Queue = %s\nInitial Head Position = %u\nSubmitted = "
      "%u\nExpected = %u\n-> %s\n\n",
      stringer(length, request_queue, req_str), initial_head_position,
      submitted, expected, submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  {
    const unsigned* request_queue = NULL;
    unsigned initial_head_position = 12;
    unsigned expected = 0;
    tester(0, request_queue, initial_head_position, expected);
  }
  {
    const unsigned request_queue[8] = {98, 183, 37, 122, 14, 124, 65, 67};
    unsigned initial_head_position = 53;
    unsigned expected = 236;
    tester(8, request_queue, initial_head_position, expected);
  }
  {
    const unsigned request_queue[6] = {33, 25, 109, 201, 15, 22};
    unsigned initial_head_position = 83;
    unsigned expected = 306;
    tester(6, request_queue, initial_head_position, expected);
  }
  {
    const unsigned request_queue[7] = {110, 3, 15, 90, 33, 12, 16};
    unsigned initial_head_position = 100;
    unsigned expected = 117;
    tester(7, request_queue, initial_head_position, expected);
  }
  {
    const unsigned request_queue[6] = {23, 50, 97, 11, 102, 1};
    unsigned initial_head_position = 60;
    unsigned expected = 160;
    tester(6, request_queue, initial_head_position, expected);
  }
  {
    const unsigned request_queue[3] = {40, 60, 70};
    unsigned initial_head_position = 50;
    unsigned expected = 40;
    tester(3, request_queue, initial_head_position, expected);
  }
  return 0;
}
