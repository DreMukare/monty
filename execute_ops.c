#include "monty.h"

/**
* execute_ops - executes according to operaction code
* @stack: pointer to pointer to stack
* @line_number: number of the line
* @token: tokenized input
*
* Return: nothing
*/
void execute_ops(stack_t **stack, unsigned int line_number, char *token)
{
	int i = 0;
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	while (op[i].opcode != NULL)
	{
		if (strcmp(token, op[i].opcode) == 0)
		{
			op[i].f(stack, line_number);
			return;
		}
		i++;
	}

	printf("L%d: unknown instruction %s\n", line_number, token);
	free_stack(stack, line_number);
	exit(EXIT_FAILURE);
}
