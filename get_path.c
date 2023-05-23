#include "shell.h"
/**
 * get_path - search for the full path of a command
 * @cmd: the command
 * Return: full directory path or NULL
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
char *get_path(const char *cmd)
{
	char *cp_path, *dir_path, *token_path;

	cp_path = get_p_cp();
	if (!cp_path)
		return (NULL);
	dir_path = NULL;
	token_path = strtok(cp_path, ":");
	while (token_path != NULL)
	{
		dir_path = get_dir_p(token_path, cmd);
		if (!dir_path)
			break;
		if (check_file(dir_path) == 1)
		{
			free(cp_path);
			return (dir_path);
		} else if (check_file(dir_path) != 1)
		{
			free(dir_path);
			dir_path = NULL;
			token_path = strtok(NULL, ":");
		}
	}
	free(cp_path);
	if (check_file(cmd) == 1)
		return ((char *) cmd);
	return (dir_path);
}
