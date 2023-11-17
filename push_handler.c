#include "monty.h"
/**
 * push_handler - function to push opcode
 * @stack: stack datastructure
 * @line_number: line number in file
 * Return: NULL is returned
 */
void push_handler(stack1_t **stack, unsigned int line_number)
{
	char **data = load_linked_list(line_number, info.filename);
	*stack = info.head2;
	if (strcmp(info.mode, "stack") == 0)
	{
		if (data[1] != NULL)
			addnodefront(stack, atoi(data[1]));
	}
	else if (strcmp(info.mode, "queue") == 0)
	{
		if (data[1] != NULL)
			addnodetoend(stack, atoi(data[1]));
	}
	/*	freedata(&data);*/
}
