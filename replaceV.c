#include "shell.h"

/**
 * replace_variable - function
 * @arr_words: parameter
 * @var: parameter
 * @value: parameter
 */
void replace_variable(char **arr_words, const char *var, const char *value)
{
	int i = 0;

	while (arr_words[i] != NULL)
	{
		char *pos = _strstr(arr_words[i], var);

		if (pos != NULL)
		{
			if (_strcmp(var, "$?") == 0)
				replace_exit_code(arr_words, i, pos, var, value);
			else if (strcmp(var, "$$") == 0)
				replace_pid(arr_words, i, pos, var, value);
			else if (_strcmp(var, "$") == 0 && _strlen(var) == 1)
				replace_env_var(arr_words, i, pos, var, value);
		}
		i++;
	}
}

/**
 * replace_exit_code - replace exit code variable
 * @ar: parameter
 * @x: parameter
 * @p: parameter
 * @s: parameter
 * @v: parameter
 */
void replace_exit_code(char **ar, int x, char *p, const char *s, const char *v)
{
	char exit_code_str[EXIT_CODE_STR_SIZE];
	size_t new_len = _strlen(ar[x]) - _strlen(s) + _strlen(exit_code_str);
	char *new_word = malloc((new_len + 1) * sizeof(char));

	snprintf(exit_code_str, EXIT_CODE_STR_SIZE, "%s", v);
	if (new_word == NULL)
		exit(EXIT_FAILURE);

	_strncpy(new_word, ar[x], p - ar[x]);
	new_word[p - ar[x]] = '\0';
	_strcat(new_word, exit_code_str);
	_strcat(new_word, p + strlen(s));
	free(ar[x]);
	ar[x] = new_word;
}

/**
 * replace_pid - replace process ID variable
 * @arr: parameter
 * @x: parameter
 * @pos: parameter
 * @var: parameter
 * @v: parameter
 */
void replace_pid(char **arr, int x, char *pos, const char *var, const char *v)
{
	char pid_str[PID_STR_SIZE];
	size_t new_len = _strlen(arr[x]) - _strlen(var) + _strlen(pid_str);
	char *new_word = malloc((new_len + 1) * sizeof(char));

	snprintf(pid_str, PID_STR_SIZE, "%s", v);
	if (new_word == NULL)
		exit(EXIT_FAILURE);

	_strncpy(new_word, arr[x], pos - arr[x]);
	new_word[pos - arr[x]] = '\0';
	_strcat(new_word, pid_str);
	_strcat(new_word, pos + _strlen(var));
	free(arr[x]);
	arr[x] = new_word;
}
