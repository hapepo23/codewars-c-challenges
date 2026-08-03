/*
7 kyu
Love vs friendship
https://www.codewars.com/kata/59706036f6e5d1e22d000016
*/

int word_score(const char* word) {
  int result = 0;
  while (*word)
    result += *(word++) - 96;
  return result;
}
