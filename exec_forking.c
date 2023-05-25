#include "shell.h"

/* BY CHARIFA MASBAHI & NORA JEOUT*/
/**
 * comment - executes a command using the fork-exec
 * @s: ------------------
 * Return: err code
 */
char **comment(char **s)
{
	int i = 0;

	while (s[i] != NULL)
	{
		if (s[i][0] == '#')
		{
			free(s[i]);
			s[i] = NULL;
			break;
		}
		i++;
	}
	return (s);
}
/**
 * komod - executes a command using the fork-exec
 * @ex_str: command to execute
 * @arr: array of arguments
 * @cur_s: variable to store the status
 * @exit_code: parameter
 * Return: error code
 */
int komod(char *ex_str, char **arr, int *cur_s, int exit_code)
{
	pid_t pid = fork();
	int code = exit_code;

	if (pid == 0)
		cmd_execve(ex_str, arr);
	else if (pid < 0)
		return (errno);
	wait_kid_process(pid, cur_s);
	if (WIFEXITED(*cur_s))
		code = WEXITSTATUS(*cur_s);
	return (code);
}
/**
 * exec_forking - executes a command using the fork-exec
 * @arr_words: arr containing commands
 * @prompt: user prompt
 * @name: program name
 * @cnt: cmonad count
 * @n: ------------------
 * Return: err code
 */
int exec_forking(char **arr_words, char *prompt, char *name, int cnt, int n)
{
	char *cmd = NULL, *cmd_to_exec = NULL, *curr_cnt = NULL;
	int curr_status, ex_code = 0;
	char ex_code_str[10], pid_str[10];
	const char *variable_env;

	if (arr_words)
	{
		arr_words = comment(arr_words);
		cmd = arr_words[0];
		if (_strcmp(cmd, "/bin/ls") == 0)
		{
			exec_binLs(arr_words);
			return (0);
		}
		if (handle_multi_cmds(arr_words, prompt, name, cnt, n) == 1)
			return (0);
		cmd_to_exec = get_path(cmd);
		if (!cmd_to_exec)
		{
			curr_cnt = intToString(cnt);
			if (!is_valid(cmd))
				p_the_err(curr_cnt, name, NULL, "not found\n");
			else
				p_the_err(curr_cnt, name, cmd, "not found\n");
			free(curr_cnt);
			return (127);
		}
		snprintf(ex_code_str, sizeof(ex_code_str), "%d", ex_code);
		snprintf(pid_str, sizeof(pid_str), "%d", getpid());
		replace_variable(arr_words, "$?", ex_code_str);
		replace_variable(arr_words, "$$", pid_str);
		variable_env = arr_words[1] + 1;

		replace_variable(arr_words, "$", variable_env);
		ex_code = komod(cmd_to_exec, arr_words, &curr_status, ex_code);
	}
	if (_strncmp(*arr_words, "./", 2) != 0 && _strncmp(*arr_words, "/", 1) != 0)
		free(cmd_to_exec);
	return (ex_code);
}
