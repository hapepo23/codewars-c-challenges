/*
6 kyu
Singly Linked List - Swap Nodes
https://www.codewars.com/kata/58d91d5f024c724b50000300
*/

#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

typedef struct Node {
  int value;
  struct Node* next;
} Node;
typedef Node* LinkedList;
typedef LinkedList* PLinkedList;

char* listToString(LinkedList list);

int swapNodes(PLinkedList listPointer1,
              unsigned int index1,
              PLinkedList listPointer2,
              unsigned int index2) {
  if (DEBUG) {
    char* list1str = listToString(*listPointer1);
    char* list2str = listToString(*listPointer2);
    printf("List 1 (%d):\t%s\nList 2 (%d):\t%s\n", index1, list1str, index2,
           list2str);
    fflush(stdout);
    free(list1str);
    free(list2str);
  }
  LinkedList list1 = *listPointer1;
  LinkedList plist1 = NULL;
  unsigned int i1 = -1;
  while (list1 != NULL) {
    i1++;
    if (index1 == i1)
      break;
    plist1 = list1;
    list1 = list1->next;
  }
  if (i1 != index1)
    return 0;
  LinkedList list2 = *listPointer2;
  LinkedList plist2 = NULL;
  unsigned int i2 = -1;
  while (list2 != NULL) {
    i2++;
    if (index2 == i2)
      break;
    plist2 = list2;
    list2 = list2->next;
  }
  if (i2 != index2)
    return 0;
  // Swap next
  LinkedList savenext = list1->next;
  list1->next = list2->next;
  list2->next = savenext;
  // Swap prev->next or start
  PLinkedList pprevnext1 = plist1 == NULL ? listPointer1 : &(plist1->next);
  PLinkedList pprevnext2 = plist2 == NULL ? listPointer2 : &(plist2->next);
  LinkedList saveprevnext = *pprevnext1;
  *pprevnext1 = *pprevnext2;
  *pprevnext2 = saveprevnext;
  return 1;
}
