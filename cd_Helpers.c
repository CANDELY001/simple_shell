#include "shell.h"
/**
 * env_vars - Gets the value of an environment variable.
 * @env_name: The name of the environment variable.
 * @env_pointer: Pointer to the environment variables array.
 * Return: The value of the environment variable.
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
char *env_vars(const char *env_name, char **env_pointer)
{
	char **the_env;

	for (the_env = env_pointer; *the_env != NULL; the_env++)
	{
		if (_strncmp(env_name, *the_env, _strlen(env_name)) == 0
				&& (*the_env)[_strlen(env_name)] == '=')
		{
			return (*the_env + _strlen(env_name) + 1);
		}
	}
	return (NULL);
}

/**
 * isError - Prints an error message.
 * @msg: The error message to print.
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
void isError(const char *msg)
{
	printf("cd: %s\n", msg);
}

/**
 * get_dir - Gets the directory to change to.
 * @init_p: The initial path passed to cd.
 * Return: The directory to change to.
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
char *get_dir(const char *init_p)
{
	if (init_p == NULL)
		return (env_vars("HOME", environ));
	else if (_strcmp(init_p, "-") == 0)
		return (env_vars("OLDPWD", environ));
	else
		return ((char *)init_p);
}

/**
 * handle_cwd - Gets the current working directory.
 *
 * Return: The current working directory.
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
char *handle_cwd()
{
	char *the_cwd;

	the_cwd = getcwd(NULL, 0);
	if (the_cwd == NULL)
		perror("cd");
	return (the_cwd);
}

/**
 * switch_current_dir - Changes the current working directory.
 * @dir: The directory to change to.
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
void switch_current_dir(const char *dir)
{
	int ret = chdir(directory);
	
    if (ret != 0)
        return (-1);

    return (0);
}
