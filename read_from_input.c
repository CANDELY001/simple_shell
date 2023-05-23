#include "shell.h"
/**
 * read_from_input  - reads input
 * @read_buf: the chars
 * Return: 1 if read else 0
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
int read_from_input(char *read_buf)
{
	ssize_t start = read(STDIN_FILENO, read_buf, 1);

	if (start == -1)
		return (0);
	if (start == 0)
	{
		if (read_buf != NULL)
			read_buf[0] = '\0';
		return (0);
	}
	return (start);
}
