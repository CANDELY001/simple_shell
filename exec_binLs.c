#include "shell.h"
/**
 * exec_binLs - handle /bin/ls
 * @arr_words: arr containing commands
 * Return: void
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
void exec_binLs(char **arr_words)
{
	pid_t pid;
	int curr_status;

	pid = fork();
	if (pid == 0)
	{
		cmd_execve("/bin/ls", arr_words);
	} else if (pid < 0)
	{
		perror("Error forking");
		return;
	}
	else
		waitpid(pid, &curr_status, 0);
}
