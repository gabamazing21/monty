#include "monty.h"

/**
 * addnode - add node to the head stack
 * @stack_head: head of the stack
 * @new_value: new value to be added
 * Return: no return
 */
void addnode(stack_t **stack_head, int new_value)
{
	stack_t *new_node, *temp;

	temp = *stack_head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp != NULL)
		temp->prev = new_node;

	new_node->n = new_value;
	new_node->next = *stack_head;
	new_node->prev = NULL;
	*stack_head = new_node;
}
