/*
6 kyu
Singly Linked List - Swap Nodes
https://www.codewars.com/kata/58d91d5f024c724b50000300
*/

#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node* next;
} Node;
typedef Node* LinkedList;
typedef LinkedList* PLinkedList;

int swapNodes(PLinkedList listPointer1,
              unsigned int index1,
              PLinkedList listPointer2,
              unsigned int index2) {
  LinkedList list1 = *listPointer1;
  LinkedList plist1 = NULL;
  int i1 = -1;
  while (list1 != NULL) {
    i1++;
    if ((int)index1 == i1)
      break;
    plist1 = list1;
    list1 = list1->next;
  }
  if (i1 != (int)index1)
    return 0;
  LinkedList list2 = *listPointer2;
  LinkedList plist2 = NULL;
  int i2 = -1;
  while (list2 != NULL) {
    i2++;
    if ((int)index2 == i2)
      break;
    plist2 = list2;
    list2 = list2->next;
  }
  if (i2 != (int)index2)
    return 0;
  // Swap next
  LinkedList savenext = list1->next;
  list1->next = list2->next;
  list2->next = savenext;
  // Swap prev->next or startptr
  PLinkedList pprevnext1 = plist1 == NULL ? listPointer1 : &(plist1->next);
  PLinkedList pprevnext2 = plist2 == NULL ? listPointer2 : &(plist2->next);
  LinkedList saveprevnext = *pprevnext1;
  *pprevnext1 = *pprevnext2;
  *pprevnext2 = saveprevnext;
  return 1;
}
