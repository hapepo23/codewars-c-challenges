/*
8 kyu
Convert a Boolean to a String
https://www.codewars.com/kata/551b4501ac0447318f0009cd
*/

#include <stdbool.h>

const char* boolean_to_string(bool b) {
  static const char* t = "true";
  static const char* f = "false";
  return b ? t : f;
}
