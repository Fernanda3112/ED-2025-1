#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "stack.h"

/*
   Print stack
*/

static void print_stack(const Stack *stack) {
	ListNode *node;
	double *data;
	int size, i;
	

	fprintf(stdout, "Stack size is %d\n", size = stack_size(stack));

	i = 0;
	node = list_head(stack);

	while (i < size) {
		data = list_data(node);
		fprintf(stdout, "stack[%03d]=%.3f, %p -> %p\n", i, *data, node, node->next);
		node = list_next(node);
	 	i++;
	}
	return;
}

int main(int argc, char const *argv[]) {
	Stack stack;
	double *data;
	int i;
	

	// Initialize the stack
	stack_init(&stack, free);

	fprintf(stdout, "\nPushing 10 elements\n");

	for (i = 1; i < 10; i++) {
		if ((data = (double *)malloc(sizeof(double))) == NULL)
	    	return 1;

	   		*data = (i + 1) * 1.50;

		if (stack_push(&stack, data) != 0)
	    	return 1;
	}
	print_stack(&stack);

	fprintf(stdout, "\nPopping 3 elements\n");
	for (i = 0; i < 3; i++) {
		if(stack_pop(&stack, (void **)&data) == 0)
			free(data);
		else
			return 1;
	}
	print_stack(&stack);

	fprintf(stdout, "\nPushing 320.657 and 765.230\n");
	if ((data = (double *)malloc(sizeof(double))) == NULL)
		return 1;
	*data = 320.657;
	if (stack_push(&stack, data) != 0)
		return 1;

	if ((data = (double *)malloc(sizeof(double))) == NULL)
		return 1;
	*data = 765.230;
	if (stack_push(&stack, data) != 0)
		return 1;
	print_stack(&stack);

	if ((data = stack_peek(&stack)) != NULL)
		fprintf(stdout, "\nPeeking at the top element [value]=%.3f\n", *data);
	else
		fprintf(stdout, "\nPeeking at the top element [value]=NULL\n");
	print_stack(&stack);

	fprintf(stdout, "\nPopping all elements\n");
	while (stack_size(&stack) > 0) {
		if (stack_pop(&stack, (void **)&data) == 0)
			free(data);
	}
	if ((data = stack_peek(&stack)) != NULL)
		fprintf(stdout, "\nPeeking at the top element [value]=%.3fd\n", *data);
	else
		fprintf(stdout, "\nPeeking at the top element [value]=NULL\n");
	print_stack(&stack);

	fprintf(stdout, "\nDestroying the stack\n");
	stack_destroy(&stack);
	return 0;
}
