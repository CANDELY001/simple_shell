#include "shell.h"
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
			return (s);
		}
		i++;
	}
	return (s);
}
/**
 * command - executes a command using the fork-exec
 * @arr_words: arr containing commands
 * @cmd: user prompt
 * @name: program name
 * @cnt: cmonad count
 * @exec: ------------------
 * Return: err code
 */
/* BY CHARIFA MASBAHI &NORA JEOUT*/
int command(char **arr_words, char *cmd, char *exec, char *name, int cnt)
{
	int ex_code = 0, curr_status;
	char *curr_cnt;
	pid_t pid;

	if (_strcmp(cmd, "/bin/ls") == 0)
	{
		exec_binLs(arr_words);
		return (0);
	}
	if (handle_multi_cmds(arr_words, prompt, name, cnt, n) == 1)
		return (0);
	if (!exec)
	{
		curr_cnt = intToString(cnt);
		if (!is_valid(cmd))
			p_the_err(curr_cnt, name, NULL, "not found\n");
		else
			p_the_err(curr_cnt, name, cmd, "not found\n");
		free(curr_cnt);
		return (127);
	}
	if (_strcmp(cmd, "exit") == 0)
	{
		free(exec);
		exit(ex_code);
	}
	pid = fork();
	if (pid == 0)
		cmd_execve(exec, arr_words);
	else if (pid < 0)
		return (errno);
	wait_kid_process(pid, &curr_status);
	if (WIFEXITED(curr_status))
		ex_code = WEXITSTATUS(curr_status);

	return (ex_code);
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
	char *cmd = NULL, *cmd_to_exec = NULL;

	if (arr_words)
	{
		arr_words = comment(arr_words);
		if (arr_words == NULL || arr_words[0] == NULL)
			return (0);
		cmd = arr_words[0];
		cmd_to_exec = get_path(cmd);
	}
	if (arr_words && _strncmp(*arr_words, "./", 2) != 0
			&& _strncmp(*arr_words, "/", 1) != 0)
		free(cmd_to_exec);

	return (command(arr_words, cmd, cmd_to_exec, name, cnt));
}

