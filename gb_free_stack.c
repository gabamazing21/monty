#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * @stack_head: head of the stack
 */
void free_stack(stack_t *stack_head)
{
	stack_t *temp;

	temp = stack_head;
	while (stack_head)
	{
		temp = stack_head->next;
		free(stack_head);
		stack_head = temp;
	}
}

