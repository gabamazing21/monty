#include "monty.h"

/**
 * f_sub - subtraction operation
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
 */
void f_sub(stack_t **stack_head, unsigned int line_number)
{
	stack_t *temp;
	int result, num_nodes;

	temp = *stack_head;

	for (num_nodes = 0; temp != NULL; num_nodes++)
		temp = temp->next;

	if (num_nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	temp = *stack_head;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*stack_head = temp->next;
	free(temp);
}
