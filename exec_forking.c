#include "shell.h"

/**
 * exec_forking - executes a command using the fork-exec
 * @arr_words: arr containing commands
 * @prompt: user prompt
 * @name: program name
 * @cnt: command count
 * @n: ------------------
 * Return: err code
 */
/*BY CHARIFA MASABHI & NORA JEOUT*/
int exec_forking(char **arr_words, char *prompt, char *name, int cnt, int n)
{
	int ex_code = 0;
	char *cmd = NULL, *cmd_to_exec = NULL, *curr_cnt = NULL;

	if (arr_words)
	{
		if (!handle_special_commands(arr_words, name))
		{
			cmd = arr_words[0];
			if (_strcmp(cmd, "/bin/ls") == 0)
				return (exec_binLs(arr_words));

			cmd_to_exec = get_path(cmd);
			if (!cmd_to_exec)
				return (handle_cmd_not_found(cnt, name, cmd));

			ex_code = execute_command(cmd_to_exec, arr_words);
			free_cmd_to_exec(arr_words, cmd_to_exec);
		}
	}

	return (ex_code);
}

/**
 * handle_cmd_not_found - handles command not found scenario
 * @cnt: command count
 * @name: program name
 * @cmd: command
 * Return: error code
 */
int handle_cmd_not_found(int cnt, char *name, char *cmd)
{
	char *curr_cnt = intToString(cnt);

	if (!is_valid(cmd))
		p_the_err(curr_cnt, name, NULL, "not found\n");
	else
		p_the_err(curr_cnt, name, cmd, "not found\n");

	free(curr_cnt);
	return (127);
}
