/*
6 kyu
Valid Phone Number
https://www.codewars.com/kata/525f47c79f2f25a4db000025
*/

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool valid_phone_number(const char* number) {
  if (strlen(number) != 14)
    return false;
  return number[0] == '(' && isdigit(number[1]) && isdigit(number[2]) &&
         isdigit(number[3]) && number[4] == ')' && number[5] == ' ' &&
         isdigit(number[6]) && isdigit(number[7]) && isdigit(number[8]) &&
         number[9] == '-' && isdigit(number[10]) && isdigit(number[11]) &&
         isdigit(number[12]) && isdigit(number[13]);
}
