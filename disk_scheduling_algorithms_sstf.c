/*
7 kyu
Disk scheduling algorithms: SSTF
https://www.codewars.com/kata/63e50629be9fe90024f3a749
*/

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>

unsigned sstf(size_t length,
              const unsigned request_queue[length],
              unsigned initial_head_position) {
  unsigned total = 0;
  unsigned head = initial_head_position;
  bool visited[length];
  for (size_t n = 0; n < length; n++)
    visited[n] = false;
  for (size_t n = 0; n < length; n++) {
    size_t best = length;
    unsigned min_distance = UINT_MAX;
    for (size_t i = 0; i < length; i++) {
      if (visited[i])
        continue;
      unsigned distance = request_queue[i] > head ? request_queue[i] - head
                                                  : head - request_queue[i];
      if (distance < min_distance) {
        min_distance = distance;
        best = i;
      }
    }
    visited[best] = true;
    total += min_distance;
    head = request_queue[best];
  }
  return total;
}
