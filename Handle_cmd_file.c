#include "shell.h"
/**
 * run_commands_from_file - Funcion
 * @filename: parameter
 */
void run_commands_from_file(char *filename)
{
	FILE *file = fopen(filename, "r");
	char line[MAX_COMMAND_LENGTH];

	if (file == NULL)
	{
		printf("Error opening file: %s\n", filename);
		return;
	}
	while (fgets(line, sizeof(line), file))
	{
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		exec_file(line);
	}

	fclose(file);
}
/**
 * exec_file - function
 * @command: parameter
 */
void exec_file(char *command)
{
	pid_t pid = fork();
	
	if (command[0] == '#')
		return;
	if (pid < 0)
	{
		printf("Forking child process failed.\n");
		return;
	} else if (pid == 0)
	{
		char *args[MAX_ARGS];
		int num_args = tokenize_command(command, args);

		if (execvp(args[0], args) == -1)
		{
			printf("Command execution failed: %s\n", args[0]);
			exit(EXIT_FAILURE);
		}

		exit(EXIT_SUCCESS);
	} else
	{
		int status;

		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			printf("Child process exited with status: %d\n", exit_status);
		}
	}
}
/**
 * tokenize_command - function
 * @command: parameter
 * @args: parameter
 * Return: result
 */
int tokenize_command(char *command, char *args[])
{
	int i = 0;
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	return (i);
}
