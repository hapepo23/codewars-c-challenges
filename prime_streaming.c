/*
3 kyu
Prime Streaming (PG-13)
https://www.codewars.com/kata/5519a584a73e70fa570005f5
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  uint64_t composite;
  uint64_t step;
} entry_t;

typedef struct {
  uint64_t current;
  entry_t* heap;
  size_t size;
  size_t cap;
} prime_stream_t;

static void swap(entry_t* a, entry_t* b) {
  entry_t t = *a;
  *a = *b;
  *b = t;
}

static void heap_up(entry_t* h, size_t i) {
  while (i > 0) {
    size_t p = (i - 1) / 2;
    if (h[p].composite <= h[i].composite)
      break;
    swap(&h[p], &h[i]);
    i = p;
  }
}

static void heap_down(entry_t* h, size_t n, size_t i) {
  for (;;) {
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;
    size_t m = i;
    if (l < n && h[l].composite < h[m].composite)
      m = l;
    if (r < n && h[r].composite < h[m].composite)
      m = r;
    if (m == i)
      break;
    swap(&h[i], &h[m]);
    i = m;
  }
}

prime_stream_t* prime_stream_new(void) {
  prime_stream_t* s = malloc(sizeof(*s));
  if (!s)
    return NULL;
  s->current = 1;
  s->size = 0;
  s->cap = 1024;
  s->heap = malloc(s->cap * sizeof(entry_t));
  if (!s->heap) {
    free(s);
    return NULL;
  }
  return s;
}

static void push(prime_stream_t* s, uint64_t composite, uint64_t step) {
  if (s->size == s->cap) {
    s->cap *= 2;
    s->heap = realloc(s->heap, s->cap * sizeof(entry_t));
  }
  s->heap[s->size] = (entry_t){composite, step};
  heap_up(s->heap, s->size);
  s->size++;
}

unsigned prime_stream_next(prime_stream_t* s) {
  if (s->current == 1) {
    s->current = 3;
    return 2;
  }
  for (;;) {
    uint64_t n = s->current;
    s->current += 2;
    while (s->size && s->heap[0].composite <= n) {
      entry_t e = s->heap[0];
      s->heap[0] = s->heap[--s->size];
      heap_down(s->heap, s->size, 0);
      if (e.composite == n) {
        push(s, n + e.step, e.step);
        goto next_candidate;
      }
      push(s, e.composite + e.step, e.step);
    }
    push(s, n * n, 2 * n);
    return (unsigned)n;
  next_candidate:
    continue;
  }
}

void prime_stream_destroy(prime_stream_t* s) {
  if (!s)
    return;
  free(s->heap);
  free(s);
}
