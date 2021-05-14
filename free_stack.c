#include "monty.h"

/**
* free_stack - frees the entire stack
* @stack: stack to be freed
* @line_number: number of the line
*
* Return: nothing
*/
void free_stack(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		return;
	while (*stack != NULL)
		pop(stack, line_number);
}
