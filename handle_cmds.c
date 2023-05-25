#include "shell.h"
/**
 * handle_multi_cmds - handle env, setenv, unsetenv cmds, handle cd, alias
 * @arr: the cmds provided
 * @name: program name
 * @cnt: cmonad count
 * @n: ------------------
 * @ppt: _______________
 * Return: 1 if one of the cmd is found or 0
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
int handle_multi_cmds(char **arr, char *ppt, char *name, int cnt, int n)
{
	char *cmd = arr[0];
	int cmd_was_handled = 0;
	(void)name, (void)cnt, (void)n, (void)ppt;

	if (_strcmp(cmd, "env") == 0)
	{
		handle_env();
		cmd_was_handled = 1;
	} else if (_strcmp(cmd, "setenv") == 0)
	{
		if (arr[1] && arr[2])
			_setenv(arr[1], arr[2], 1);
		else
			perror("Usage: setenv VARIABLE VALUE\n");
		cmd_was_handled = 1;
	} else if (_strcmp(cmd, "unsetenv") == 0)
	{
		if (arr[1])
			_unsetenv(arr[1]);
		else
			perror("Usage: unsetenv VARIABLE\n");
		cmd_was_handled = 1;
	} else if (_strcmp(cmd, "cd") == 0)
	{
		handle_cd(arr);
		cmd_was_handled = 1;
	}
	return (cmd_was_handled);
}
