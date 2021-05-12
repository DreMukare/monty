#include "monty.h"

/**
 * main - entry into interpreter
 * @argc: argc counter
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *buffer, **tokens;
	int i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	buffer = file_open(argv[1]);

	tokens = tokenizer(buffer);

	while (tokens[i] != NULL)
	{
		printf("%s\n", tokens[i]);
		i++;
	}
	/* place to call other functions then close file */

	free(buffer);
	freer(tokens);
	return (0);
}
