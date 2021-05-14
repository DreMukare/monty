#include "monty.h"

/**
* tokenizer - tokenizes string
* @input: string to be tokenized
* @stack: pointer to pointer to stack
* @line_number: the number of the line where command is
*
* Return: nothing
*/
void tokenizer(char *input, stack_t **stack, unsigned int line_number)
{
	char *token = NULL, *tokens = NULL;

	token = strtok(input, " ");
	if (!token || *token == '\n' || *token == '#' || *token == ' ')
		return;
	if (strcmp(token, "push") == 0)
	{
		tokens = token;
		token = strtok(NULL, " ");
		if (check_digit(token) == 0)
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
			free_stack(stack, line_number);
			exit(EXIT_FAILURE);
		}
		variable.value = atoi(token);
		execute_ops(stack, line_number, tokens);
	}
	else
		execute_ops(stack, line_number, token);
}
