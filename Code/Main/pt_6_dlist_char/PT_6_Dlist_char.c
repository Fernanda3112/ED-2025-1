#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

/*
  Print DList
*/

static void print_dlist (const DList *dlist) {
    DListNode *node;
    char *data;
    int i;
    
    fprintf(stdout, "List size is %d\n", dlist_size(dlist));

    i = 0;
    node = dlist_head(dlist);
	
	 while (1) {
	 	
        data = (char *)dlist_data(node);
        fprintf(stdout, "list.node[%03d]=%c, %p -> %p \n", i, *data, node, node->next);

        i++;

        if (dlist_is_tail(node))
            break;
        else
            node = dlist_next(node);
    }

   return;
}    

int main (int argc, char **argv) {
	DList dlist;
	DListNode *node;
	
	char *data;
    int i;
	
	// Initialize the linked list
	dlist_init (&dlist, free);
	
	// Fill the linked list
    node = dlist_head(&dlist);
    for (i = 20; i > 10; i--) {

        if ((data = (char *)malloc(sizeof(char))) == NULL)
            return 1;
		
		//It will start at z.
        *data = (char)(i + 90 - 20);

        if (dlist_ins_next(&dlist, dlist_tail(&dlist), data) != 0)
			return 1;
    }

	print_dlist (&dlist);
	
	node = dlist_head(&dlist);
	
	for (i = 0; i < 7; ++i)
        node = dlist_next(node);

    data = (char*)dlist_data(node);

	//Insert next node at the List

 	fprintf(stdout, "\nInserting 'A' at the tail of the list\n");
    if ((data = (char *)malloc(sizeof(char))) == NULL)
        return 1;
    *data = 'A';
    if (dlist_ins_next(&dlist, dlist_tail(&dlist), data) != 0)
        return 1;

    print_dlist(&dlist);  
    
    
   	//Insert next node at the dlist 
    fprintf(stdout, "\nInserting 'B' at the head of the list\n"); 
		if ((data = (char *)malloc(sizeof(char))) == NULL)
    return 1;
	*data = 'B';

	// dlist_ins_prev 
	if (dlist_ins_prev(&dlist, dlist_head(&dlist), data) != 0) 
    return 1;

	print_dlist(&dlist);

	//Removing
	fprintf(stdout, "\nRemoving a node after the first node\n");
    if (dlist_remove (&dlist, dlist_head(&dlist), (void**)&data) != 0)
        return 1;
    print_dlist(&dlist);
    
    
    fprintf(stdout, "\nRemoving the sixth node\n");
    node = dlist_head(&dlist);
    node = dlist_next(node); // first node
    node = dlist_next(node); // second node
    node = dlist_next(node); // third node
    node = dlist_next(node);
    node = dlist_next(node);
    node = dlist_next(node);
    if (dlist_remove(&dlist, node, (void**)&data) != 0)
        return 1;
    print_dlist(&dlist);
	

    // Testing if head and tail
    i = dlist_is_head(node); 
    fprintf(stdout, "\nTesting dlist_is_head... value=%d (1=OK)\n", i);
    i = dlist_is_head(dlist_tail(&dlist)); 
    fprintf(stdout, "Testing dlist_is_head... value=%d (0=OK)\n", i);
    i = dlist_is_tail(node); 
    fprintf(stdout, "Testing dlist_is_tail... value=%d (1=OK)\n", i);
    i = dlist_is_tail(dlist_head(&dlist)); 
    fprintf(stdout, "Testing dlist_is_tail... value=%d (0=OK)\n", i);

    // Destroying the list
    fprintf(stdout, "\nDestroying the list\n");
    dlist_destroy(&dlist); 

    return 0;
}
