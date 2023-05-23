#include "shell.h"
/**
 * get_p_cp - Gets a copy of the PATH env var
 * Return: result
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
char *get_p_cp()
{
	char *path = getenv("PATH");
	char *path_cp;

	if (!path)
		return (NULL);
	path_cp = _strdup(path);
	if (!path_cp)
		return (NULL);
	return (path_cp);
}
