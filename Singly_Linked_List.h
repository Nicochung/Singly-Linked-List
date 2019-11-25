//
//  Singly_Linked_List.h
//  
//
//  Created by Nico Chung on 25/11/2019.
//

#ifndef Singly_Linked_List_h
#define Singly_Linked_List_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include stdbool.h to use bool datatype
#endif /* Singly_Linked_List_h */

// typedef <old name> <new name>;
// We use unsigned int as an example, and alias it as VALUE
typedef unsigned int VALUE;

// Define a singly linked list node
typedef struct sllist
{
    // Value can be anydata type
    VALUE val;
   struct sllist* next;
}
sllnode;

/* Operations in singly-linked lists
 1. Create a linked list when it doesn't already exist.
 2. Search througha linked list to find an element.
 3. Insert a new node into the linked list
 4. Delete a single element from a linked list
 5. Delete an entire linked list.
*/

// Create a linked list
sllnode* create(VALUE val);

// Seach through a linked list to find an element
bool find(sllnode* head, VALUE val);

// Insert a new node into the linked list (Insert in the front)
sllnode* insert_front(sllnode** head, VALUE val);

// Destroy an entire linked list
void destroy(sllnode* head);

// Print every element on the list
void print_list(sllnode* head);
