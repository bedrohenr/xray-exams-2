#include "linkedlist.h"

void ll_remove_by_id(LinkedList *l, const int id){
   for (ListNode *p = l->first; p != NULL; p = p->next)
   {
      if (p->type == STRUCT_TYPE)
         destroy_patient(p->info); // Print the information of each Student structure.
      else
         destroy_exam(p->info); // Print the information of each Professor structure.
   }
   printf("\n"); // Print a newline character to separate the output.
}