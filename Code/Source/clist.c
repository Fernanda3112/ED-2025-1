#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

/*
    Print the circular list
*/
static void print_clist(const CList *list) {
    CListNode *node;
    float *data;
    int i;

    fprintf(stdout, "Circular list size is %d\n", clist_size(list));

    i = 0;
    node = clist_head(list);

    do {
        data = (float *)clist_data(node);
        fprintf(stdout, "clist.node[%03d] = %.2f, %p -> %p\n", i, *data, node, clist_next(node));

        i++;
        node = clist_next(node);
    } while (node != clist_head(list)); // iterate until returning to the head

    return;
}

int main(int argc, char **argv) {
    CList clist;
    CListNode *node;

    float *data;
    int i;

    // Initialize the circular list
    clist_init(&clist, free);

    // Fill the linked circular list
    node = clist_head(&clist);
    for (i = 20; i > 10; i--) {
        if ((data = (float *)malloc(sizeof(float))) == NULL)
            return 1;
		// 0.3 is for it to be float
        *data = (float)i + 0.3f; 
        
        // Insert at the head 
  		if (clist_ins_next(&clist, node == NULL ? clist_head(&clist) : node, data) != 0) {
			return 1;
		}

        node = clist_head(&clist); // Set node to head for circular insertion
    }

    print_clist(&clist);


    fprintf(stdout, "\nInserting 24.45 at the head of the circular list\n");
    if ((data = (float *)malloc(sizeof(float))) == NULL)
        return 1;
    *data = 24.45f;
    if (clist_ins_next(&clist, clist_head(&clist), data) != 0)
        return 1;

    print_clist(&clist);

    fprintf(stdout, "\nRemoving a node after the head\n");
    if (clist_rem_next(&clist, clist_head(&clist), (void **)&data) != 0)
        return 1;

    print_clist(&clist);
    
    
    fprintf(stdout, "\nInserting 0.7 the quarter node\n");
    node = clist_head(&clist);
    node = clist_next(node); // Primer nodo
    node = clist_next(node); // Segundo nodo
    node = clist_next(node); // Tercer nodo
    if ((data = (float *)malloc(sizeof(float))) == NULL)
        return 1;
    *data = 0.7f;
    if (clist_ins_next(&clist, node, data) != 0)
        return 1;

    print_clist(&clist);
    
    
    fprintf(stdout, "\nRemoving the Third node\n");

    node = clist_head(&clist);
    node = clist_next(node);
    node = clist_next(node);
    if (clist_rem_next(&clist, node, (void **)&data) != 0)
        return 1;

    print_clist(&clist);
    
    

    // Destroying the circular list
    fprintf(stdout, "\nDestroying the circular list\n");
    clist_destroy(&clist);

    return 0;
}
