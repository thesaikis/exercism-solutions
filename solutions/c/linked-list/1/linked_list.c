#include <stdlib.h>

#include "linked_list.h"

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

struct list *list_create(void) {
   struct list* new_list = malloc(sizeof(struct list));

   new_list->first = NULL;
   new_list->last = NULL;

   return new_list;
}

size_t list_count(const struct list *list) {
   if (!list->first) {
      return 0;
   }

   size_t count = 0;
   struct list_node *pointer = list->first;

   while (pointer) {
      count++;
      pointer = pointer->next;
   }

   return count;
}

void list_push(struct list *list, ll_data_t item_data) {
   struct list_node *new_node = malloc(sizeof(struct list_node));
   
   if (list->last) {
      list->last->next = new_node;
   }

   new_node->data = item_data;
   new_node->next = NULL;
   new_node->prev = list->last;

   list->last = new_node;

   if (list->first == NULL) {
      list->first = new_node;
   }
}

ll_data_t list_pop(struct list *list) {
   ll_data_t to_return = list->last->data;

   list->last = list->last->prev;

   if (list->last == NULL) {
      list->first = NULL;
   } else {
      list->last->next = NULL;
   }

   return to_return;
}

void list_unshift(struct list *list, ll_data_t item_data) {
   struct list_node *new_node = malloc(sizeof(struct list_node));

   if (list->first) {
      list->first->prev = new_node;
   }

   new_node->data = item_data;
   new_node->next = list->first;
   new_node->prev = NULL;

   list->first = new_node;

   if (list->last == NULL) {
      list->last = new_node;
   }
}

ll_data_t list_shift(struct list *list) {
   ll_data_t to_return = list->first->data;

   list->first = list->first->next;

   if (list->first) {
      list->first->prev = NULL;
   }
   
   return to_return;
}

void list_delete(struct list *list, ll_data_t data) {
   struct list_node *pointer = list->first;

   if (pointer->data == data) {
      list->first = list->first->next;

      if (list->first) {
         pointer->prev = NULL;
      }

      return;
   }

   while (pointer) {
      if (pointer->next && pointer->next->data == data) {
         pointer->next = pointer->next->next;

         if (pointer->next == NULL) {
            list->last = pointer;
         } else {
            pointer->next->prev = pointer;
         }

         return;
      }

      pointer = pointer->next;
   }

   // matching data was never found
   return;
}

void list_destroy(struct list *list) {
   struct list_node *to_delete = list->first;

   while (to_delete) {
      struct list_node *temp = to_delete->next;
      free(to_delete);
      to_delete = temp;
   }

   free(list);
}
