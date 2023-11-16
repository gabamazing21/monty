#include "monty.h"

/**
 * f_push - add node to the stack
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
 */
void f_push(stack_t **stack_head, unsigned int line_number)
{
	int value, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack_head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	value = atoi(bus.arg);

	if (bus.lifi == 0)
		addnode(stack_head, value);
	else
		addqueue(stack_head, value);
}
