/*
7 kyu
Split by Mask
https://www.codewars.com/kata/6a68ed7894f29599a1f7a248
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t split_by_mask(const char* string,
                     size_t masks_len,
                     const size_t masks[masks_len],
                     char* parts[masks_len]);

static char* masker(size_t length, const size_t array[length], char* arr_str) {
  if (length) {
    size_t index = 0, pos = sprintf(arr_str, "{");
    while (index < length) {
      pos += sprintf(arr_str + pos, "%zu%s", array[index],
                     (index == length - 1) ? "" : ", ");
      index++;
    }
    sprintf(arr_str + pos, "}");
  } else {
    sprintf(arr_str, "NULL");
  }
  return arr_str;
}

static char* stringer(size_t length, const char* array[length], char* arr_str) {
  if (length) {
    size_t index = 0, pos = sprintf(arr_str, "{");
    while (index < length) {
      pos += sprintf(arr_str + pos, "\"%s\"%s", array[index],
                     (index == length - 1) ? "" : ", ");
      index++;
    }
    sprintf(arr_str + pos, "}");
  } else {
    sprintf(arr_str, "NULL");
  }
  return arr_str;
}

static void tester(const char* string,
                   size_t masks_len,
                   const size_t masks[masks_len],
                   size_t expected_len,
                   const char* const expected[expected_len]) {
  char** submitted = masks_len ? malloc(masks_len * sizeof(char*)) : NULL;
  size_t string_len = strlen(string);
  for (size_t index = 0; index < masks_len; index++) {
    submitted[index] = malloc((string_len + 1) * sizeof(char));
  }
  size_t submitted_len = split_by_mask(string, masks_len, masks, submitted);
  bool passing = submitted_len == expected_len;
  if (passing) {
    for (size_t index = 0; index < expected_len; index++) {
      if (strcmp(submitted[index], expected[index])) {
        passing = false;
        break;
      }
    }
  }
  char msk_str[1024];
  char exp_str[16384];
  char sub_str[16384];
  printf("String = \"%s\"\nMasks = %s\nSubmitted: %s\nExpected:  %s\n-> %s\n\n",
         string, masker(masks_len, masks, msk_str),
         stringer(submitted_len, (const char**)submitted, sub_str),
         stringer(expected_len, (const char**)expected, exp_str),
         passing ? "OK" : "FAIL");
  free(submitted);
  submitted = NULL;
}

int main(void) {
  {
    const char* string = "";
    const size_t* masks = NULL;
    const char** expected = NULL;
    tester(string, 0, masks, 0, expected);
  }
  {
    const char* string = "1234567890";
    const size_t masks[3] = {3, 3, 4};
    const char* const expected[3] = {"123", "456", "7890"};
    tester(string, 3, masks, 3, expected);
  }
  {
    const char* string = "codewars";
    const size_t masks[2] = {4, 4};
    const char* const expected[2] = {"code", "wars"};
    tester(string, 2, masks, 2, expected);
  }
  return 0;
}
