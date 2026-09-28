/*
7 kyu
Password entropy
https://www.codewars.com/kata/6a1f03fac18f58f98ad9d21a
*/

#include <math.h>
#include <stdio.h>

double entropy(const char* password);

static void tester(const char* password, double expected) {
  double actual = entropy(password);
  printf("Password = \"%s\", expected = %.10g, actual = %.10g -> %s\n",
         password, expected, actual,
         fabs(expected - actual) < 1e-6 ? "OK" : "FAIL");
}

int main(void) {
  tester("hello", 23.502198590705458);
  tester("Hello", 28.502198590705458);
  tester("Hell0", 29.770981551934376);
  tester("He||0", 32.772944258388186);
  tester("Tr0ub4dor&3", 72.100477368454010);
  tester("correcthorsebatterystaple", 117.510992953527290);
  tester("CorrectHorseBatteryStaple", 142.510992953527300);
  tester("Correct_Horse_Battery_Staple", 178.984887837805300);
  return 0;
}
