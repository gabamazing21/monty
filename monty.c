#include "main.h"
int main(int argc,char *argv [])
{
	FILE *file;
	const char *file_name = argv[1];
	file = fopen(file_name,"r");
	char *line = NULL;
	size_t len;
	char DELIMETER = " \t\n"
	if (argc < 2)
	{
		printf("USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}
	else if(file == NULL)
	{
		printf("Error: Can't open file %d\n", *file_name);
	}
	else
	{
		while ((read = getline(&line, &len,file)) != -1)
		{
			char *token = strtok(line, DELIMETER);
			printf("%d\n", *token);
			while (token != NULL)
			{
				token = strtok(NULL, DELIMETER);
				printf("%d\n",token);
			}
		}
	}
}
