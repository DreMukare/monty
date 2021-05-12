#include "monty.h"

/**
 * main - entry into interpreter
 * @argc: argc counter
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
  int fd;
  char *buffer;
  ssize_t n_read;

  if (argc != 2)
    {
      printf("USAGE: monty file\n");
      exit(EXIT_FAILURE);
    }
  fd = open(argv[1], O_RDONLY);
  if (fd == -1)
    {
      printf("Error: Can't open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }
  buffer = malloc(sizeof(char) * 10000);
  if (!buffer)
    return (0);
  n_read = read(fd, buffer, 10000);
  if (n_read == -1)
    {
      free(buffer);
      close(fd);
      exit(EXIT_FAILURE);
    }

  free(buffer);
  close(fd);
  return (0);
}
