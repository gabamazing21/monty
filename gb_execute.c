#include "monty.h"

/**
 * execute - executes the opcode
 * @line_content: line content from file
 * @stack_head: head of the linked list (stack)
 * @line_counter: line counter
 * @monty_file: pointer to monty file
 * Return: no return
 */
int execute(char *line_content, stack_t **stack_head, unsigned int line_counter, FILE *monty_file)
{
	instruction_t operations[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{"queue", f_queue},
		{"stack", f_stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *operation;

	operation = strtok(line_content, " \n\t");
	if (operation && operation[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (operations[i].opcode && operation)
	{
		if (strcmp(operation, operations[i].opcode) == 0)
		{
			operations[i].f(stack_head, line_counter);
			return (0);
		}
		i++;
	}
	if (operation && operations[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, operation);
		fclose(monty_file);
		free(line_content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	return (1);
}
