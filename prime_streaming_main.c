/*
3 kyu
Prime Streaming (PG-13)
https://www.codewars.com/kata/5519a584a73e70fa570005f5
*/

#include <stdio.h>

typedef struct prime_stream prime_stream_t;

prime_stream_t* prime_stream_new(void);
unsigned prime_stream_next(prime_stream_t*);
void prime_stream_destroy(prime_stream_t*);

int main(void) {
  prime_stream_t* stream = prime_stream_new();
  printf("1) Expected = 2 -> %s\n",
         prime_stream_next(stream) == 2 ? "OK" : "FAIL");
  printf("2) Expected = 3 -> %s\n",
         prime_stream_next(stream) == 3 ? "OK" : "FAIL");
  printf("3) Expected = 5 -> %s\n",
         prime_stream_next(stream) == 5 ? "OK" : "FAIL");
  printf("4) Expected = 7 -> %s\n",
         prime_stream_next(stream) == 7 ? "OK" : "FAIL");
  printf("5) Expected = 11 -> %s\n",
         prime_stream_next(stream) == 11 ? "OK" : "FAIL");
  printf("6) Expected = 13 -> %s\n",
         prime_stream_next(stream) == 13 ? "OK" : "FAIL");
  printf("7) Expected = 17 -> %s\n",
         prime_stream_next(stream) == 17 ? "OK" : "FAIL");
  printf("8) Expected = 19 -> %s\n",
         prime_stream_next(stream) == 19 ? "OK" : "FAIL");
  printf("9) Expected = 23 -> %s\n",
         prime_stream_next(stream) == 23 ? "OK" : "FAIL");
  printf("10) Expected = 29 -> %s\n",
         prime_stream_next(stream) == 29 ? "OK" : "FAIL");
  printf("Streaming 999989 more primes (not shown) ...\n");
  for (int i = 1; i <= 999989; i++)
    prime_stream_next(stream);
  printf("1000000) Expected = 15485863 -> %s\n",
         prime_stream_next(stream) == 15485863 ? "OK" : "FAIL");
  printf("Streaming 999999 more primes (not shown) ...\n");
  for (int i = 1; i <= 999999; i++)
    prime_stream_next(stream);
  printf("2000000) Expected = 32452843 -> %s\n",
         prime_stream_next(stream) == 32452843 ? "OK" : "FAIL");
  prime_stream_destroy(stream);
  return 0;
}
