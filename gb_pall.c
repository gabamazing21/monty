#include "monty.h"

/**
 * f_display_stack - prints the stack
 * @head: stack head
 * @counter: not used
 * Return: no return
 */
void f_display_stack(stack_t **head, unsigned int counter)
{
	/* Declare a pointer to stack node */
	stack_t *current_node;
	(void)counter;

	/* Assign head to the current_node */
	current_node = *head;

	/* If the stack is empty, return */
	if (current_node == NULL)
		return;

	/* Loop through the stack and print values */
	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
