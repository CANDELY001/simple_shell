#include "shell.h"
/**
 * _unsetenv - Unset an environment variable.
 * @name: The name of the env var to unset.
 * Return: 0 on success, or -1.
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
int _unsetenv(const char *name)
{
	int final_result;

	if (!name || name[0] == '\0')
	{
		perror("unsetenv: invalid env name\n");
		return (-1);
	}
	final_result = unsetenv(name);
	if (final_result < 0)
		perror("unsetenv: failed to unset env\n");
	return (final_result);
}
