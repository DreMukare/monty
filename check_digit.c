#include "monty.h"

/**
* check_digit - checks if current character is numeric
* @token: string to be checked
*
* Return: 1 if number, 0 if not
*/
int check_digit(char *token)
{
	if (!token)
		return (0);
	if (*token == '-')
		token++;
	while (*token != '\0')
	{
		if (!isdigit(*token))
			return (0);
		token++;
	}
	token++;
	return (1);
}
