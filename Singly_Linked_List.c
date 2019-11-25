//
//  Singly_Linked_List.c
//  
//
//  Created by Nico Chung on 25/11/2019.
//

#include "Singly_Linked_List.h"

// Create a linked list
/* Steps involced:
 a. Dynamically allocate space for a new sllnode.
 b. Check to make sure we didn't run out of memory.
 c. Initialize the nodes's val field.
 d. Initailize the node's next field.
 e. return a pointer to the newly created sllnode.
 */
sllnode* create(VALUE val)
{
    //  a. Dynamically allocate space for a new sllnode.
    sllnode* new = malloc(val);
    //  b. Check to make sure we didn't run out of memory.
    // Note that !new is true if the pointer is NULL, not NULL is somevalue.
    // New is NULL
    if (!new)
    {
        // We run out of memeory, return NULL to the user
        return NULL;
    }
    // New is a not a NULL, do the followings
    else
    {
        // We got memory
        // c. Initialize the nodes's val field.
        // d. Initailize the node's next field.
        // e. return a pointer to the newly created sllnode.
        new->val = val;
        new->next = NULL;
        fprintf(stderr, "We have manage to create a node with value %d\n", new->val);
        return new;
    }
}

// Search through a linked list to find an element
/* Steps involved:
 a. Create a travsersal pointer pointing to the list's head
 b. If the current node's val field is what we're looking for, report true
 c. If not, set the traversal pointer to the next pointer in the list and go back to step b.
 d. If you've reached the end of the list, report failure.
 */
bool find(sllnode* head, VALUE val)
{
    //  a. Create a travsersal pointer pointing to the list's head
    // The for loop ends if tral->val == val, aka the val is found
    for (sllnode* trav = head; trav->val != val; trav = trav->next)
    {
        // c. If not, set the traversal pointer to the next pointer in the list and go back to step b.
        // d. If you've reached the end of the list, report failure.
        if (!trav) // same as tral == NULL
        {
            fprintf(stderr, "We have manage to reach a NULL, tral == NULL\n");
            return false;
        }
    }
    fprintf(stderr, "We have manage to exit the loop\n");
    // b. If the current node's val field is what we're looking for, report true
    /*
    if (trav.val == val)
    {
        return true;
    }
     */
    fprintf(stderr, "We have manage to reach the end of function\n");
    return true;
}

// Insert a new node into the linked list (Insert in the front)
/* Steps involved:
 a. Dynamically allocate space for a new sllnode
 b. Check to make sure we didn't run out of memory
 c. Populate and inset the node at the beginning of the linked list
 d. Return a pointer to the new head of the linked list.
 */
// Note that we are passing pointer of pointer into this function.
// If we are just passing in the pointer head, it is actually call by value.
sllnode* insert_front(sllnode** headptr, VALUE val)
{
    // Call function "create" to create a new node
    // a. Dynamically allocate space for a new sllnode
    sllnode* new = create(val);
    
    // Check whether "create" return a NULL pointer
    // b. Check to make sure we didn't run out of memory
    if (!new) // Same as new == NULL
    {
        fprintf(stderr, "New is NULL\n");
        return NULL;
    }
    fprintf(stderr, "New is not NULL\n");
    // c. Populate and inset the node at the beginning of the linked list
    new->next = *headptr;
    *headptr = new;
    // d. Return a pointer to the new head of the linked list.
    return new;
}

// Delete an entire linked list (recursion)
/* Steps involved:
 a. If you've reached a null pointer, stop
 b. Delete the rest of the list.
 c. Free the current node
 */
void destroy(sllnode* head)
{
    // The base case is reach the NULL pointer/ last node.
    // a. If you've reached a null pointer, stop

    if(!head) // Same as head == NULL
    {
        fprintf(stderr, "We have manage to reach NULL / at of the list\n");
    }
    else
    {
        // b. Delete the rest of the list.
        destroy(head->next);
        // c. Free the current node
        fprintf(stderr, "We have manage to free node value %i\n", head->val);
        free(head);
    }
}
       
// print every element on the list
void print_list(sllnode* head)
{
    sllnode* trav = head;
    unsigned int cnt = 0;
    if (!trav)
    {
        printf("Empty List, the head is NULL");
    }
    else
    {
        while(trav) // Same as head !=NULL
        {
            printf("Element %d in the list, Value stored is %d\n", cnt++, trav->val);
            trav = trav->next;
        }
    }
}
