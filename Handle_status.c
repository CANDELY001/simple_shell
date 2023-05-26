#include "shell.h"
/**
 * handle_exit_status - Handles exit built-in command.
 * @arr: commands
 * @ppt: user input.
 * @name: program name
 * @c: conter of commands
 * @n: number of commands
 * Return: void.
 */
/*BY CHARIFA MASBAHI & NORA JEOUT*/
void handle_exit_status(char **arr, char *ppt, char *name, int c, int n)
{
	int ex_stat = 0;

	if (arr[1] != NULL)
	{
		if (_isdigit(arr[1][0]))
		{
			ex_stat = _atoi(arr[1]) % 256;
		} else
		{
			ex_err(arr, c, name);
			free(ppt);
			free_words(arr, n);
			exit(2);
		}
	}

	free(ppt);
	free_words(arr, n);
	exit(ex_stat);
}
