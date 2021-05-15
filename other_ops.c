#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack
 * @head: stack pointer
 * @line_number: line number
 * Return: void
 */
void _pchar(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (isascii(variable.value))
		printf("%c\n", variable.value);
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pstr -prints the string starting at the top of the stack
 * @head: stack pointer
 * @line_number: line number
 * Return: void
 */
void _pstr(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	stack_t *str;

	if (head == NULL || *head == NULL || variable.value == 0)
	{
		printf("\n");
		return;
	}

	str = *head;

	while (str != NULL && str->n != 0 && isascii(str->n))
	{
		printf("%c", str->n);
		str = str->next;
	}
	printf("\n");
}

/**
 * _rotl - rotates the stack to the top
 * @head: stack pointer
 * @line_number: line number
 * Return: void
 */
void _rotl(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	stack_t *temp;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *head;
	(*head)->prev = temp;
	*head = (*head)->next;
	(*head)->prev = NULL;
	temp->next->next = NULL;
}

/**
 * _rotr -rotates the stack at the bottom
 * @head: stack pointer
 * @line_number: line number
 * Return: void
 */
void _rotr(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	stack_t *temp;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	*head = temp;
}
