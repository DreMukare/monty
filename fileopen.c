#include "monty.h"

/**
* file_open - opens file and stores contents in buffer
* @file: file to be read
*
* Return: buffer containing file contents on success
*/
char *file_open(char *file)
{
	FILE *fp = NULL;
	char *buf = NULL;
	int prev, sz, result = access(file, F_OK);

	fp = fopen(file, "r");
	if (!fp || result != 0)
	{
		dprintf(STDERR_FILENO, "Error: can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	prev = ftell(fp);
	fseek(fp, 0L, SEEK_END);
	sz = ftell(fp);
	fseek(fp, prev, SEEK_SET);
	buf = malloc(sizeof(char) * sz + 1);
	if (buf)
	{
		fread(buf, sizeof(char), sz, fp);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	fclose(fp);

	return (buf);
}
