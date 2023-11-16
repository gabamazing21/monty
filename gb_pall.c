#include "monty.h"

/**
 * f_pall - prints the stack
 * @stack_head: stack head
 * @line_number: not used
 * Return: no return
 */
void f_pall(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack_head;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
