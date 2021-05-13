#include "monty.h"

/**
* tokenizer - tokenizes string
* @input: string to be tokenized
*
* Return: array of tokenized string
*/
char **tokenizer(char *input)
{
	char **tokens = NULL;
	char *buf = NULL, *bufp = NULL, *token = NULL, *delim = "\n";
	size_t i = 0, flag = 0;
	int tokensize = 1;

	buf = strdup(input);
	if (!buf)
		return (NULL);
	bufp = buf;

	while (*bufp)
	{
		if (strchr(delim, *bufp) != NULL && flag == 0)
		{
			tokensize++;
			flag = 1;
		}
		else if (strchr(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}

	tokens = malloc(sizeof(char *) * (tokensize + 1));
	token = strtok(buf, delim);

	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while (token)
	{
		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = '\0';
	free(buf);
	return (tokens);
}
