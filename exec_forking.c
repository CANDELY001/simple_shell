#include "shell.h"
/**
 * exec_forking - executes a command using the fork-exec
 * @arr_words: arr containing commands
 * @prompt: user prompt
 * @name: program name
 * @cnt: cmonad count
 * @n: ------------------
 * Return: err code
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/

int exec_forking(char **arr_words, char *prompt, char *name, int cnt, int n)
{
	char *cmd = NULL, *cmd_to_exec = NULL, *curr_cnt = NULL;
	pid_t pid;
	int curr_status, ex_code = 0;
	char ex_code_str[10];
	char pid_str[10];
	const char *variable_env = arr_words[1] + 1;

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
		replace_variable(arr_words, "$", variable_env);
		pid = fork();
		if (pid == 0)
			cmd_execve(cmd_to_exec, arr_words);
		else if (pid < 0)
			return errno;
		wait_kid_process(pid, &curr_status);
		if (WIFEXITED(curr_status))
			ex_code = WEXITSTATUS(curr_status);
	}
	if (_strncmp(*arr_words, "./", 2) != 0 && _strncmp(*arr_words, "/", 1) != 0)
		free(cmd_to_exec);
	return (ex_code);
}
