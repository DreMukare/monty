#include "monty.h"

/**
 * main - entry into interpreter
 * @argc: argc counter
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *buffer;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	buffer = file_open(argv[1]);

	printf("%s\n", buffer);
	/* place to call other functions then close file */

	free(buffer);
	return (0);
}
