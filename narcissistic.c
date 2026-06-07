/*
6 kyu
Does my number look big in this?
https://www.codewars.com/kata/5287e858c6b5a9678200083c
*/

#include <stdbool.h>

bool narcissistic(int num) {
  return (num >= 0 && num <= 9) || num == 153 || num == 370 || num == 371 ||
         num == 407 || num == 1634 || num == 8208 || num == 9474 ||
         num == 54748 || num == 92727 || num == 93084 || num == 548834 ||
         num == 1741725 || num == 4210818 || num == 9800817 || num == 9926315 ||
         num == 24678050 || num == 24678051 || num == 88593477 ||
         num == 146511208 || num == 472335975 || num == 534494836 ||
         num == 912985153;
}
