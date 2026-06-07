/*
7 kyu
Combining Ratios
https://www.codewars.com/kata/69e3d400196a47ceacde554f
*/

#include <stdio.h>

typedef long long ll;

static ll gcd(ll a, ll b) {
  while (b != 0) {
    ll t = b;
    b = a % b;
    a = t;
  }
  return a;
}

static ll gcd3(ll a, ll b, ll c) {
  return gcd(gcd(a, b), c);
}

void merge_ratios(const char* ratio1, const char* ratio2, char* result) {
  ll a, b, c, d;
  sscanf(ratio1, "%lld:%lld", &a, &b);
  sscanf(ratio2, "%lld:%lld", &c, &d);
  ll x = a * c;
  ll y = b * c;
  ll z = b * d;
  ll g = gcd3(x, y, z);
  x /= g;
  y /= g;
  z /= g;
  sprintf(result, "%lld:%lld:%lld", x, y, z);
}
