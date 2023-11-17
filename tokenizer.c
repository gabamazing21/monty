#include "monty.h"
/**
 * tokenizer - generates tokens
 * @line: =====
 * Return: tokens arrays
 */
char **tokenizer(char *line)
{
	const char delimiters[] = " \n\t$";
	/*	char **tokens = malloc(1024 * sizeof(char*));*/
	/*	char *tokens[1024];*/
	int numTokens = 0;
	char *token;

	token = strtok(line, delimiters);
	if (token == NULL)
		return (NULL);
	while (token != NULL)
	{
		/*tokens[numTokens] = token;*/
		info.var._token[numTokens] = token;
		numTokens++;
		token = strtok(NULL, delimiters);
	}
	return (info.var._token);
}
