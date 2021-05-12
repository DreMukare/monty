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

	/**
	* first tokenize
	* check if each token is valid, if not throw error using index as line no
	* if valid, execute according to command
	* in that while loop, a function to check validity will be passed.
	* then after we'll run each command
	* so we pass in the full token, tokenize again, to get the number and the command
	* then execute
	*/

	free(buffer);
	freer(tokens);
	return (0);
}
