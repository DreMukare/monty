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
      dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line_number);
      exit(EXIT_FAILURE);
    }
}
