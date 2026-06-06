/*
6 kyu
Singly Linked List - Swap Nodes
https://www.codewars.com/kata/58d91d5f024c724b50000300
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int value;
  struct Node* next;
} Node;
typedef Node* LinkedList;
typedef LinkedList* PLinkedList;

int swapNodes(PLinkedList listPointer1,
              unsigned int index1,
              PLinkedList listPointer2,
              unsigned int index2);

static LinkedList createList(const int array[], int size) {
  LinkedList result = NULL;
  LinkedList prev = NULL;
  for (int i = 0; i < size; i++) {
    LinkedList n = malloc(sizeof(Node));
    n->value = array[i];
    n->next = NULL;
    if (prev == NULL)
      result = n;
    else
      prev->next = n;
    prev = n;
  }
  return result;
}

char* listToString(LinkedList list) {
  char* s = malloc(100);
  s[0] = '\0';
  while (list != NULL) {
    if (s[0] != '\0')
      s = strcat(s, " -> ");
    sprintf(s + strlen(s), "%d", list->value);
    list = list->next;
  }
  return s;
}

static int areLinkedListsEqual(LinkedList l1, LinkedList l2) {
  char* sl1 = listToString(l1);
  char* sl2 = listToString(l2);
  int result = (strcmp(sl1, sl2) == 0) ? 1 : 0;
  free(sl1);
  free(sl2);
  return result;
}

static void freeList(LinkedList list) {
  while (list != NULL) {
    LinkedList nx = list->next;
    free(list);
    list = nx;
  }
}

void do_test(int l1[],
             size_t length1,
             unsigned int i1,
             int l2[],
             size_t length2,
             unsigned int i2) {
  LinkedList list1 = createList(l1, length1);
  LinkedList list2 = createList(l2, length2);
  char* slist1 = listToString(list1);
  char* slist2 = listToString(list2);
  printf("list1 = %s | list2 = %s\nSwap %d and %d\n", slist1, slist2, i1, i2);
  free(slist1);
  free(slist2);
  int* l1new = (int*)malloc(sizeof(int) * length1);
  int* l2new = (int*)malloc(sizeof(int) * length2);
  for (size_t i = 0; i < length1; ++i)
    l1new[i] = (i == i1 && i2 < length2) ? l2[i2] : l1[i];
  for (size_t i = 0; i < length2; ++i)
    l2new[i] = (i == i2 && i1 < length1) ? l1[i1] : l2[i];
  LinkedList list1new = createList(l1new, length1);
  LinkedList list2new = createList(l2new, length2);
  char* slist1new = listToString(list1new);
  char* slist2new = listToString(list2new);
  printf("exp1  = %s | exp2  = %s\n", slist1new, slist2new);
  free(slist1new);
  free(slist2new);
  int res = swapNodes(&list1, i1, &list2, i2);
  printf("Swap result = %d\n", res);
  char* rlist1 = listToString(list1);
  char* rlist2 = listToString(list2);
  printf("act1  = %s | act2  = %s\n", rlist1, rlist2);
  free(rlist1);
  free(rlist2);
  if (res == (i1 < length1 && i2 < length2))
    printf("OK   ");
  else
    printf("FAIL ");
  if (areLinkedListsEqual(list1, list1new))
    printf("OK   ");
  else
    printf("FAIL ");
  if (areLinkedListsEqual(list2, list2new))
    printf("OK  \n");
  else
    printf("FAIL\n");
  free(l1new);
  free(l2new);
  freeList(list1);
  freeList(list2);
  freeList(list1new);
  freeList(list2new);
  puts("");
}

int main(void) {
  int initialList1[] = {1, 2, 3, 4, 5, 6};
  int initialList2[] = {7, 8, 9};
  do_test(initialList1, 6, 1, initialList2, 3, 1);
  do_test(initialList1, 6, 0, initialList2, 3, 1);
  do_test(initialList1, 6, 1, initialList2, 3, 2);
  do_test(initialList1, 6, 5, initialList2, 3, 1);
  do_test(initialList1, 6, 5, initialList2, 3, 3);
  do_test(initialList1, 6, 6, initialList2, 3, 1);
  do_test(initialList1, 6, 0, initialList2, 3, 18);
  return 0;
}
