#include "shell.h"
/**
 * handle_cd - handle cd command
 * @arr_words: the arr of words
 * Return: void
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
void handle_cd(char **arr_words)
{
	char *initial_directory = NULL, *the_old_pwd, *the_curr_pwd;

	if (arr_words[1] == NULL)
	{
		initial_directory = env_vars("HOME", environ);
	}
	else if (_strcmp(arr_words[1], "-") == 0)
	{
		initial_directory = env_vars("the_old_pwd", environ);
		if (initial_directory == NULL)
		{
			isError("OLDPWD not set");
			return;
		}
	}
	else
	{
		initial_directory = (char *)arr_words[1];
	}

	the_old_pwd = handle_cwd();
	if (the_old_pwd == NULL)
		return;

	if (_setenv("OLDPWD", the_old_pwd, 1) < 0)
	{
		free(the_old_pwd);
		return;
	}
	free(the_old_pwd);

	switch_current_dir(initial_directory);

	the_curr_pwd = handle_cwd();
	if (the_curr_pwd == NULL)
		return;

	if (_setenv("PWD", the_curr_pwd, 1) < 0)
	{
		free(the_curr_pwd);
		return;
	}
	free(the_curr_pwd);
}
