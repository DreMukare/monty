#include "monty.h"

/**
 * push - push an element to the stack
 * @head: head pointer(at bottom of stack)
 * @line_number: bytecode line number
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new;

	if (head == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free_stack(head, line_number);
		exit(EXIT_FAILURE);
	}
	new->n = variable.value;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
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
		exit(EXIT_FAILURE);
	}
	if ((*head)->next != NULL)
	{
		*head = (*head)->next;
		variable.value = (*head)->n;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
	else
	{
		free(*head);
		*head = NULL;
	}
}
