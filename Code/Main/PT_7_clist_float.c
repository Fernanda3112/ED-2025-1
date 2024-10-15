/*
    clist.c
*/

#include <stdlib.h>
#include <string.h>
#include "clist.h"

/*
    Initialize the circular list
*/
void clist_init(CList *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    return;
}

/*
    Destroy the circular list
*/
void clist_destroy(CList *list) {
    void *data;

    while (clist_size(list) > 0) {
        if (clist_rem_next(list, list->head, (void **)&data) == 0 && list->destroy != NULL) {
            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(CList));
    return;
}


//    Insert next node 

int clist_ins_next(CList *list, CListNode *node, const void *data) {
    CListNode *new_node;

    if ((new_node =(CListNode *)malloc(sizeof(CListNode))) == NULL)
        return -1;

    new_node->data = (void *)data;

    // If the list is empty
    if (clist_size(list ) == 0) {
        new_node->next = new_node;
        list->head =new_node;
    } else {
        // Insert the new node
        new_node->next = node->next;
        node->next = new_node;
    }

    list-> size++;

    return 0;
}


//    Remove node 

int clist_rem_next(CList *list, CListNode *node, void **data) {
    CListNode *old_node;

    // Check if is not empty the list
    if (clist_size(list) ==0)
        return -1;

    // If the list has only one node
    if (node ==list->head && clist_size(list) == 1) {
        *data = list->head->data;
        old_node = list->head;
        list->head = NULL;
    } else {
        // If removing the head node with multiple nodes
        if (node->next ==list->head) {
            old_node = list->head;
            *data = list->head->data;

            // aux is used to find the last node
            CListNode *aux =list->head;

            // Find the node before the head
            while (aux->next !=list->head)
                aux = aux->next;

            // Update the head the last node points to the new head
            list->head =list->head->next;
            aux->next =list->head;
        } else {
            // Removing a node other than the head
            old_node = node->next;
            *data =old_node->data;
            node->next = old_node->next;
        }
    }

    // Free the old node
    free(old_node);

    // Decrement the list size
    list-> size--;

    return 0;
}
