#include "shell.h"
/**
 * check_file - Checks if a file exists
 * @path: path
 * Return: 1 if the file exists, 0 otherwise
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
int check_file(const char *path)
{
	struct stat buffer;

	if (stat(path, &buffer) != 0)
		return (0);
	return (1);
}
