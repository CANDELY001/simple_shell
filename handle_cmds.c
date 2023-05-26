#include "shell.h"
/**
 * handle_multi_cmds_Helper - handle env, setenv..
 * @arr: the cmds provided
 * Return: 1 if one of the cmd is found or 0
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
int handle_multi_cmds_Helper(char **arr)
{
	char *cmd = arr[0], *variable_env,
	     pid_str[PID_STR_SIZE], ex_code_str[EXIT_CODE_STR_SIZE];

	if (_strcmp(cmd, "alias") == 0)
	{
		exec_alias(arr);
		return (1);
	} else if (_strcmp(cmd, "unalias") == 0)
	{
		exec_alias(arr);
		return (1);
	} else if (_strcmp(cmd, "simple_shell") == 0)
	{
		char *filename = arr[1];

		run_commands_from_file(filename);
		return (1);
	} else if (_strcmp(cmd, "echo") == 0 && _strcmp(arr[1], "$$") == 1)
	{
		snprintf(pid_str, sizeof(pid_str), "%d", getpid());
		replace_variable(arr, "$$", pid_str);
		return (1);
	} else if (_strcmp(cmd, "echo") == 0 && _strcmp(arr[1], "$?") == 1)
	{
		snprintf(ex_code_str, sizeof(ex_code_str), "%d", ex_code);
		replace_variable(arr, "$?", ex_code_str);
		return (1);
	} else if (_strcmp(cmd, "echo") == 0 && arr[1][0] == '$')
	{
		variable_env = arr[1] + 1;
		replace_variable(arr, "$", variable_env);
		return (1);
	}
	return (0);
}
/**
 * handle_multi_cmds - handle env, setenv, unsetenv cmds, handle cd, alias
 * @arr: the cmds provided
 * @name: program name
 * @cnt: cmonad count
 * @n: ------------------
 * @ppt: _______________
 * Return: 1 if one of the cmd is found or 0
 */
int handle_multi_cmds(char **arr, char *ppt, char *name, int cnt, int n)
{
	char *cmd = arr[0];
	int cmd_was_handled = 0, ex_code = 0;
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
		{
			perror("Usage: setenv VARIABLE VALUE\n");
		}
		cmd_was_handled = 1;
	} else if (_strcmp(cmd, "unsetenv") == 0)
	{
		if (arr[1])
			_unsetenv(arr[1]);
		else
		{
			perror("Usage: setenv VARIABLE VALUE\n");
		}
		cmd_was_handled = 1;
	} else if (_strcmp(cmd, "cd") == 0)
	{
		handle_cd(arr);
		cmd_was_handled = 1;
	} else if (handle_multi_cmds_Helper(arr) == 1)
	{
		cmd_was_handled = 1;
	}
	return (cmd_was_handled);
}
