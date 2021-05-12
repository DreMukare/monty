#include "monty.h"

/**
 * pall - print values on stack, starting from top of stack
 * @head: head pointer
 *@line_number: node number
 *Return: nothing
 */
void pall(stack_t **head, unsigned int line_number)
{
  stack_t temp = NULL;
  if (!head || !*head)/*account for empty stack*/
    return;
  (void) line_number;
  temp = *head;
  while (temp != NULL)/*print data in stack*/
    {
      printf("%d\n", temp->n);
      temp = temp->next;
    }
}

/**
 *pint - prints the value at the top of the stack
 *@head: head pointer
 *line_number: node number
 *Return: nothing
 */
void pint(stack_t **head, unsigned int line_number)
{
  if (!head || !*head)
    {
      printf("L%u: can't pint, stack empty\n", line_number);
      exit(EXIT_FAILURE);
    }
  printf("%d\n", head->n);/*print top value*/
}

/**
 * swap - swaps the top two elements of the stack
 * @head: node to be swapped
 * @line_number: node number
 */
void swap(stack_t **head, unsigned int line_number)
{
  stack_t *temp = NULL;
  
  /*if stack got less than 2 elements*/
  if (*head == NULL || (*head)->next == NULL)
    {
      printf("L%u: can't swap, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }
  temp = (*head)->next;
  if (temp->next != NULL)
    {
      (*head)->next = temp->next;
      (*head)->next->prev = *head;

    }
  else
    {
      temp->prev->prev = temp;
      temp->prev->next = NULL;
    }
  temp->prev = NULL;
  temp->next = *head;
  (*head) = temp;
}

/**
 *
 */
void nop(stack_t **head, unsigned int line_number)
{
  (void) head;
  (void) line_number;
  return;
}
