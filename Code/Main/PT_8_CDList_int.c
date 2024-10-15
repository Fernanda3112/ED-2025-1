#include <stdio.h>
#include <stdlib.h>
#include "cdlist.h"

/*
    Print the circular linked double list
*/
static void print_cdlist(const CDList *cdlist) {
	CDListNode *node;
	int *data, size, i;
	

	fprintf(stdout, "Circular double list size is %d\n", size = cdlist_size(cdlist));

	i = 0;
	node = cdlist_head(cdlist);

	while (i < size) {
		data = cdlist_data(node);
		fprintf(stdout, "queue[%03d]=%03d, %p -> %p\n", i, *data, node, node->next);
		node = cdlist_next(node);
	 	i++;
	}
	return;
}

int main(int argc, char **argv) {
    CDList cdlist;
    CDListNode *node;
    int *data, i;

    // Initialize the circular linked double list
    cdlist_init(&cdlist, free);

    // Fill the circular linked double list
    node = cdlist_head(&cdlist);
    for (i = 0; i < 20; i++) {
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;
		
        *data = i + 1; 
        
        // Insert at the head 
        if (cdlist_ins_next(&cdlist, node == NULL ? cdlist_head(&cdlist) : node, data) != 0)
            return 1;

        node = cdlist_head(&cdlist); // Set node to head for circular insertion
    }

    print_cdlist(&cdlist);


    fprintf(stdout, "\nInserting 26 at the head of the circular list\n");
    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;
    *data = 26;
    if (cdlist_ins_next(&cdlist, cdlist_head(&cdlist), data) != 0)
        return 1;

    print_cdlist(&cdlist);

    fprintf(stdout, "\nRemoving a node after the first node\n");
    if (cdlist_remove(&cdlist, cdlist_head(&cdlist), (void **)&data) != 0)
        return 1;

    print_cdlist(&cdlist);
    
    
    fprintf(stdout, "\nInserting 31 after the quarter node\n");
    node = cdlist_head(&cdlist);
    node = cdlist_next(node); // Primer nodo
    node = cdlist_next(node); // Segundo nodo
    node = cdlist_next(node); // Tercer nodo
    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;
    *data = 31;
    if (cdlist_ins_next(&cdlist, node, data) != 0)
        return 1;

    print_cdlist(&cdlist);
    
    
    fprintf(stdout, "\nIterating and removing the fourth node\n");

    node = cdlist_head(&cdlist);
    node = cdlist_next(node);
    node = cdlist_next(node);
    if (cdlist_remove(&cdlist, node, (void **)&data) != 0)
        return 1;

    print_cdlist(&cdlist);
    
    

    // Destroying the circular list
    fprintf(stdout, "\nDestroying the circular list\n");
    cdlist_destroy(&cdlist);

    return 0;
}
