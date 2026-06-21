/*
8 kyu
Was the package received before it was sent?
https://www.codewars.com/kata/6707688c0f597511f6649270
*/

#include <stdbool.h>

bool was_package_received_yesterday(int tz_from,
                                    int tz_to,
                                    int start,
                                    int duration) {
  return start + duration + tz_to - tz_from < 0;
}
