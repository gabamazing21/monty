#include "monty.h"

bus_t monty_bus = {NULL, NULL, NULL, 0};

/**
 * monty_interpreter - monty code interpreter
 * @num_args: number of arguments
 * @file_location: monty file location
 * Return: 0 on success
 */
int main(int num_args, char *file_location[])
{
	char *line_content;
	FILE *monty_file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack_head = NULL;
	unsigned int line_counter = 0;

	if (num_args != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(file_location[1], "r");
	monty_bus.file = monty_file;
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_location[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		line_content = NULL;
		read_line = getline(&line_content, &size, monty_file);
		monty_bus.content = line_content;
		line_counter++;
		if (read_line > 0)
		{
			execute(line_content, &stack_head, line_counter, monty_file);
		}
		free(line_content);
	}
	free_stack(stack_head);
	fclose(monty_file);
	return (0);
}
