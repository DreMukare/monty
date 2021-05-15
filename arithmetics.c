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

	adding = variable.value;
	pop(stack, line_number);
	adding += variable.value;
	pop(stack, line_number);
	variable.value = adding;
	push(stack, line_number);
}

/**
 * sub - subtracts top two elements on stack
 * @stack: stack pointer
 * @line_number: line number
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int subtract;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
	}

	subtract = variable.value;
	pop(stack, line_number);
	subtract = variable.value - subtract;
	pop(stack, line_number);
	variable.value = subtract;
	push(stack, line_number);
}

/**
 * _div - divides second top element of stack by top of stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int divide;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n",
			line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
	}
	if (variable.value == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n",
			line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
	}

	divide = variable.value;
	pop(stack, line_number);
	divide = variable.value / divide;
	pop(stack, line_number);
	variable.value = divide;
	push(stack, line_number);
}

/**
 * _mul - multiplies second top element of stack with top element
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int multiply;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n",
			line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
	}

	multiply = variable.value;
	pop(stack, line_number);
	multiply = variable.value * multiply;
	pop(stack, line_number);
	variable.value = multiply;
	push(stack, line_number);
}

/**
 * _mod -computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int rem;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n",
			line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
	}
	if (variable.value == 0)
	{
		printf("L%d: division by zero\n", line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
	}

	rem = variable.value;
	pop(stack, line_number);
	rem = variable.value % rem;
	pop(stack, line_number);
	variable.value = rem;
	push(stack, line_number);
}
