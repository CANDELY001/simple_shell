#include "shell.h"
/**
 * help - helper function for exec_forking
 * @cmd: command
 * @s: arr containing commands
 * @p: user prompt
 * @name: program name
 * @cnt: command count
 * @n: ------------------
 * @exec: pointer to store the command to execute
 * Return: 1 if further execution is required, 0 otherwise
 */
int help(char *cmd, char **s, char *p, char *name, int cnt, int n, char **exec)
{
	if (_strcmp(cmd, "/bin/ls") == 0)
	{
		exec_binLs(s);
		return (0);
	}
	if (handle_multi_cmds(s, p, name, cnt, n) == 1)
		return (0);

	*exec = get_path(cmd);
	if (!(*exec))
	{
		char *curr_cnt = intToString(cnt);

		if (!is_valid(cmd))
			p_the_err(curr_cnt, name, NULL, "not found\n");
		else
			p_the_err(curr_cnt, name, cmd, "not found\n");
		free(curr_cnt);
		return (0);
	}

	return (1);
}
/**
 * replacvs - replaces variables in s with their values
 * @s: array of words
 * @str: string representation of the exit code value
 * @pid_str: string representation of the process ID value
 * @exit_code: parameter
 */
void replacvs(char **s, const char *str, const char *pid_str, int exit_code)
{
	char exit_code_str[10];
	char pid_str_buf[10];

	snprintf(exit_code_str, sizeof(exit_code_str), "%d", exit_code);
	snprintf(pid_str_buf, sizeof(pid_str_buf), "%d", getpid());

	replace_variable(s, "$?", exit_code_str);
	replace_variable(s, "$$", pid_str_buf);

	const char *variable_env = s[1] + 1;

	replace_variable(s, "$", variable_env);
}

/**
 * exec_forking - executes a command using the fork-exec
 * @arr_words: arr containing commands
 * @prompt: user prompt
 * @name: program name
 * @cnt: command count
 * @n: ------------------
 * Return: error code
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
int exec_forking(char **arr_words, char *prompt, char *name, int cnt, int n)
{
	char *cmd = NULL, *cmd_to_exec = NULL, *curr_cnt = NULL;
	pid_t pid;
	int curr_status;
	int exit_code = 0;
	char ex_code_str[10];
	char pid_str[10];

	if (arr_words)
	{
		int i = 0;

		while (arr_words[i] != NULL)
		{
			if (arr_words[i][0] == '#')
			{
				free(arr_words[i]);
				arr_words[i] = NULL;
				break;
			}
			i++;
		}
		cmd = arr_words[0];
		if (help(cmd, arr_words, prompt, name, cnt, n, &cmd_to_exec))
		{
			replacvs(arr_words, ex_code_str, pid_str, exit_code);
			pid = fork();
			if (pid == 0)
				cmd_execve(cmd_to_exec, arr_words);
			else if (pid < 0)
				return (errno);
			wait_kid_process(pid, &curr_status);
			if (WIFEXITED(curr_status))
				exit_code = WEXITSTATUS(curr_status);
		}
	}
	if (_strncmp(*arr_words, "./", 2) != 0 && _strncmp(*arr_words, "/", 1) != 0)
		free(cmd_to_exec);
	return (exit_code);
}
