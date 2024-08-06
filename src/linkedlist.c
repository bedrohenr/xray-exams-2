#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list.
struct list
{
   int count;       // Number of elements in the linked list.
   ListNode *first; // A pointer to the first node in the linked list.
   ListNode *last;  // A pointer to the last node in the linked list.
};

// Define a structure for a node in the linked list.
struct list_node
{
   NodeType type;
   void *info;     // Data associated with the node (generic pointer).
   ListNode *prev; // A pointer to the previous node in the linked list.
   ListNode *next; // A pointer to the next node in the linked list.
};

// Create an empty linked list and return a pointer to it.
LinkedList *ll_create()
{
   LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
   l->first = NULL;
   l->last = NULL;
   l->count = 0;
   return l;
}

// Insert an element at the beginning of the linked list.
void ll_insert(LinkedList *l, void *info, NodeType type){
   ListNode *node = (ListNode *)malloc(sizeof(ListNode));
   node->type = type;
   node->info = info;
   node->next = l->first;

   if (!ll_is_empty(l))
      l->first->prev = node;
   else
      l->last = node;

   l->first = node;
   l->count++;
}

void ll_append(LinkedList *l, void *data, NodeType type){
   ListNode *node = (ListNode *)malloc(sizeof(ListNode));
   node->type = type;
   node->info = data;
   node->next = NULL;
   node->prev = NULL;

   if (ll_is_empty(l)){
      l->first = node;
      l->last = node;
   } else{
      l->last->next = node;
      node->prev = l->last;
      l->last = node;
   }

   l->count++;
}

void ll_clear(LinkedList *l);

// Get the number of elements in the linked list.
int ll_size(LinkedList *l)
{
   return l->count;
}

// Check whether the linked list is empty.
int ll_is_empty(LinkedList *l)
{
   return ll_size(l) == 0;
}

void *ll_get(LinkedList *l, int pos){
   int count = 0;
   for (ListNode *p = l->first; p != NULL; p = p->next){
      if(count == pos){
         return p;
      }
      count++;
   }
}

void ll_free(LinkedList *l){
    ListNode *p = l->first;
    ListNode *t;
    while (p != NULL){
        t = p->next;   // Store a reference to the next node.
        free(p->info); // Free the memory allocated for the Student structure.
        free(p);       // Free the memory allocated for the current node.
        p = t;         // Move to the next node.
    }
    free(l); // Free the memory allocated for the list structure itself.
}

// Display all elements of the linked list.
void ll_print(LinkedList *l){
   for (ListNode *p = l->first; p != NULL; p = p->next){
      if (p->type == TYPE_STUDENT)
         st_print(p->info); // Print the information of each Student structure.
      else
         pr_print(p->info); // Print the information of each Professor structure.
   }
   printf("\n"); // Print a newline character to separate the output.
}

void ll_print_reversed(LinkedList *l){
   for (ListNode *p = l->last; p != NULL; p = p->prev){
      if (p->type == TYPE_STUDENT)
         st_print(p->info); // Print the information of each Student structure.
      else
         pr_print(p->info); // Print the information of each Professor structure.
   }
   printf("\n"); // Print a newline character to separate the output.
}
