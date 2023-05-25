#include "shell.h"
/**
 * _setenv - Set the value of an environment variable.
 * @name: name of env var.
 * @value: The val to set the env var to.
 * @overwrite: flag
 * Return: 0 on success, or -1.
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
int _setenv(const char *name, const char *value, int overwrite)
{
	size_t namelen = _strlen(name);
	size_t value_len = _strlen(value);
	size_t total_len = namelen + value_len + 2;
	char *env_var = malloc(total_len);

	if (name == NULL || value == NULL)
		return (-1);
	if (env_var == NULL)
		return (-1);
	snprintf(env_var, total_len, "%s=%s", name, value);
	int result;

	if (overwrite)
		result = putenv(env_var);
	else
		result = setenv(name, value, 0);

	if (result != 0)
	{
		free(env_var);
		return (-1);
	}
	return (0);
}
