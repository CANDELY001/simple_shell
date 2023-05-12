#include "shell.h"

/**
 * read_input - Reads a line of input from stdin.
 * Return: A pointer to the input string, or NULL on error or empty line.
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
char *read_input()
{
	char *input_h = NULL;
	size_t alloc_size = 0;
	ssize_t total_read;

	fflush(stdout);
	total_read = getline(&input_h, &alloc_size, stdin);
	if (total_read == -1)
	{
		free(input_h);
		return (NULL);
	}
	if (total_read > 0 && input_h[total_read - 1] == '\n')
	{
		input_h[total_read - 1] = '\0';
	}
	return (input_h);
}
