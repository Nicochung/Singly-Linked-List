//
//  slltest.c
//  
//
//  Created by Nico Chung on 25/11/2019.
//

#include <stdio.h>
#include "Singly_Linked_List.h"

int main(void)
{
    
    sllnode* head = create(1);
    sllnode* temp = NULL;
    printf("Address of head is %p\n", head);
    printf("Head->val is %d\nHead->next is %p\n", head->val, head->next);
    temp = insert_front(&head, 2);
    printf("Address of temp is %p\n", temp);
    printf("Head->val is %d\nHead->next is %p\n", head->val, head->next);
    printf("temp->val is %d\ntemp->next is %p\n", temp->val, temp->next);
    insert_front(&head, 3);
    insert_front(&head, 4);
    print_list(head);
    destroy(head);
}
