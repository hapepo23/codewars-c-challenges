/*
4 kyu
The observed PIN
https://www.codewars.com/kata/5263c6999e0f40dee200059d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char** get_pins(const char* observed, size_t* count);
void free_pins(const char** pins);

static int compare_function(const void* p1, const void* p2) {
  const char* pin1 = *(const char**)p1;
  const char* pin2 = *(const char**)p2;
  return strcmp(pin1, pin2);
}

static void do_test(const char* observed,
                    size_t expected_count,
                    const char* const expected_pins[]) {
  size_t count;
  const char** pins = get_pins(observed, &count);
  printf("Observed: %s\n", observed);
  printf("Expected %zu pins, received %zu\n", expected_count, count);
  qsort(pins, count, sizeof(pins[0]), compare_function);
  for (size_t i = 0; i < count; ++i) {
    printf("PIN #%zu was expected to be '%s', but was '%s' -> %s\n", i,
           expected_pins[i], pins[i],
           strcmp(pins[i], expected_pins[i]) == 0 ? "OK" : "FAIL");
  }
  puts("\n");
  free_pins(pins);
}

int main(void) {
  const char* observed = "8";
  size_t expected_count = 5;
  const char* const expected_pins[] = {"0", "5", "7", "8", "9"};
  do_test(observed, expected_count, expected_pins);
  observed = "11";
  expected_count = 9;
  const char* const expected_pins2[] = {"11", "12", "14", "21", "22",
                                        "24", "41", "42", "44"};
  do_test(observed, expected_count, expected_pins2);
  observed = "369";
  expected_count = 36;
  const char* const expected_pins3[] = {
      "236", "238", "239", "256", "258", "259", "266", "268", "269",
      "296", "298", "299", "336", "338", "339", "356", "358", "359",
      "366", "368", "369", "396", "398", "399", "636", "638", "639",
      "656", "658", "659", "666", "668", "669", "696", "698", "699"};
  do_test(observed, expected_count, expected_pins3);
  return 0;
}
