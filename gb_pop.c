#include "monty.h"

/**
 * f_pop - removes the top element of the stack
 * @head: stack head
 * @line_number: line_number
 * Return: no return
 */
void f_pop(stack_t **head, unsigned int line_number)
{
	stack_t *current_node;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_node = *head;
	*head = current_node->next;
	free(current_node);
}
