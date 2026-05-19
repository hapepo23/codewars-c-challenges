/*
6 kyu
The Deaf Rats of Hamelin
https://www.codewars.com/kata/598106cb34e205e074000031
*/

static int leftsearch(const char* from, const char* to) {
  const char* p = from;
  int result = 0;
  while (p >= to) {
    if (*p == '~' && *(p - 1) == 'O') {
      result++;
      p -= 2;
    } else if (*p == 'O' && *(p - 1) == '~')
      p -= 2;
    else
      p--;
  }
  return result;
}

static int rightsearch(const char* from) {
  const char* p = from;
  int result = 0;
  while (*p) {
    if (*p == '~' && *(p + 1) == 'O') {
      result++;
      p += 2;
    } else if (*p == 'O' && *(p + 1) == '~')
      p += 2;
    else
      p++;
  }
  return result;
}

int countDeafRats(const char* town) {
  const char* p = town;
  while (*p) {
    if (*p == 'P')
      return leftsearch(p - 1, town) + rightsearch(p + 1);
    p++;
  }
  return 0;
}
