#include "monty.h"

/**
* freer - frees pointers to pointers
* @buf: buffer to be freed
*
* Return: nothing
*/
void freer(char **buf)
{
	int i = 0;

	if (!buf || !*buf)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}
