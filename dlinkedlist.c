#include "monty.h"

/**
 *add_end_node - add node at the end of doubly linked list
 *@head: head pointer
 *@n: data to add
 *Return: zero
 */
int add_end_node(stack_t **head, int n)
{
	stack_t *new_node = NULL;

	if (!head)
		return (-1);

	new_node = malloc(sizeof(stack_t));/*malloc new node*/
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;/*set data to new node*/
	if (*head == NULL)/*account for empty list*/
	{
		*head = new_node;
		new_node->next  = NULL;
		new_node->prev = NULL;
	}
	else /* add node at the end */
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}

	return (0);
}

/**
 *del_end_node - delete end node of a doubly linked list
 *@head: head pointer
 *Return: nothing
 */
void del_end_node(stack_t **head)
{
	stack_t *del = NULL;

	del = *head;
	if ((*head)->next == NULL)/*account for one node*/
	{
		*head = NULL;
		free(del);
	}
	else/*delete node*/
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(del);
	}
}

/**
 * free_dlist - frees a doubly linked list with only int data, no strings
 * @head: pointer to head of list
 */
void free_dlist(stack_t **head)
{
	/* return if empty list */
	if (!head)
		return;

	while (*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}
