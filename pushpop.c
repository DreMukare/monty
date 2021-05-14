#include "monty.h"
/**
 * push - push an element to the stack
 * @head: head pointer(at bottom of stack)
 * @line_number: bytecode line number
 * @n: integer to push to stack
 */
void push(stack_t **head, unsigned int line_number, int n)
{
	if (!head)
		return;

	/* not integer or no agruments given */
	if (!n)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else /* push element to stack */
	{
		if (add_end_node(head, n) == -1)
		{
			free_dlist(head);
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * pop - removes the top element of the stack
 * @head: head of list
 * @line_number: bytecode line number
 */
void pop(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)/*if stack is empty*/
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		free_dlist(head);
		exit(EXIT_FAILURE);
	}
	else /* pop element */
	del_end_node(head);
}
