#include "monty.h"

/**
 * main - entry into interpreter
 * @argc: argc counter
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
  char *buffer = NULL, *token;
  unsigned int linenum = 1;
  stack_t *stk = NULL;
	FILE *file;
	size_t n = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");/*open file*/
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &n, file) != -1)
	  {
	    /*tokenize and execute*/
	  if (buffer != '\n')/*delimiter newline*/
	    {
	      token = strtok(buffer, "\n");
	      tokenizer(token, stk, linenum)/*call the func*/
	    }
	  linenum++;
	  }
	fclose(file);
	free(buffer);
	return (0);
}
