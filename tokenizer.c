#include "monty.h"

/**
* tokenizer - tokenizes string
* @input: string to be tokenized
*
* Return: array of tokenized string
*/
char **tokenizer(char *input)
{
	char **tokens = malloc(sizeof(input));
	int i = 0;
	char *p = strtok(input, "\n");

	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while (p != NULL)
	{
		tokens[i] = p;
		i++;
		p = strtok(NULL, "\n");
	}
	
	free(p);
	return (tokens);
}
