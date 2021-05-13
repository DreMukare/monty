#include "monty.h"

/**
 * add - function to add top two elements on stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int adding;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n",
			 line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
	}

	adding = value;
	pop(stack, line_number);
	adding += value;
	pop(stack, line_number);
	value = adding;
	push(stack, line_number, value);
}
