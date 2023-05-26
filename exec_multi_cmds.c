#include "shell.h"

/**
 * execute_command - Execute a single command
 * @cmd: The command to execute
 * @prompt: The user input string
 * @sh_name: The program name
 * @cnt: The parameter
 * Return: The exit code of the command
 */
int execute_command(char *cmd, char *prompt, char *sh_name, int cnt)
{
	int num_of_words, ex_code = 0;
	char **arr_of_words = split_string(cmd, " \t\r\n", &num_of_words);
	if (arr_of_words == NULL)
	{
		perror("Error splitting command string\n");
		return 0;
	}
	if (num_of_words == 0)
	{
		free_words(arr_of_words, num_of_words);
		return 0;
	}
	if (_strcmp(arr_of_words[0], "exit") == 0)
	{
		free_words(arr_of_words, num_of_words);
		handle_exit_status(arr_of_words, prompt, sh_name, cnt, num_of_words);
	}
	ex_code = exec_forking(arr_of_words, prompt, sh_name, cnt, num_of_words);
	free_words(arr_of_words, num_of_words);
	return ex_code;
}

/**
 * exec_multi_cmds - Execute multiple commands separated by semicolons, && or ||
 * @prompt: The user input string containing the commands
 * @sh_name: The program name
 * @cnt: The parameter
 * Return: The exit code of the last command executed
 */
int exec_multi_cmds(char *prompt, char *sh_name, int cnt)
{
	int num_of_cmds, i, ex_code = 0;
	char **arr_of_cmds = NULL;

	if (strstr(prompt, ";") != NULL)
		arr_of_cmds = split_string(prompt, ";", &num_of_cmds);
	else if (strstr(prompt, "&&") != NULL)
		arr_of_cmds = split_string(prompt, "&&", &num_of_cmds);
	else if (strstr(prompt, "||") != NULL)
		arr_of_cmds = split_string(prompt, "||", &num_of_cmds);

	if (arr_of_cmds == NULL)
	{
		printf("Error splitting user input\n");
		return errno;
	}

	for (i = 0; i < num_of_cmds; i++)
	{
		ex_code = execute_command(arr_of_cmds[i], prompt, sh_name, cnt);
		if (ex_code != 0 && strstr(prompt, "||") != NULL)
			break;
		if (ex_code == 0 && strstr(prompt, "&&") != NULL)
			continue;
	}

	free_words(arr_of_cmds, num_of_cmds);
	return ex_code;
}

