#include "shell.h"
/**
 * get_dir_p - Concatenates a directory path and a command name
 * @path: path
 * @cmd: cmd
 * Return: new string with the concatenated path and command name
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
char *get_dir_p(const char *path, const char *cmd)
{
	char *dir_path = malloc(_strlen(path) + _strlen(cmd) + 2);

	if (!dir_path)
		return (NULL);
	_strcpy(dir_path, path);
	_strcat(dir_path, "/");
	_strcat(dir_path, cmd);
	return (dir_path);
}
