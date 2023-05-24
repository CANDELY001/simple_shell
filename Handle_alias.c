
#include "shell.h"
/**
 * save_alias - save the alias
 * @alias_name: name
 * @alias_value: value
 * Return: 1 (Success) 0 (failed)
 */
int save_alias(const char *alias_name, const char *alias_value)
{
	if (alias_name && alias_value)
	{
		char env_name[MAX_ALIAS_NAME_LENGTH + 7] = "ALIAS_";

		strcat(env_name, alias_name);
		_setenv(env_name, alias_value, 1);
		return (1);
	}
	return (0);
}

/**
 * add_alias - add new alias
 * @n: name
 * @v: value
 * @aliases: list
 * @alias_count: parameter
 * Return: 1 (Success) 0 (failed)
 */
int add_alias(const char *n, const char *v, int alias_count, Alias aliases)
{
	if (alias_count < MAX_ALIASES)
	{
		for (int i = 0; i < alias_count; i++)
		{
			if (strcmp(aliases[i].name, n) == 0)
			{
				_strcpy(aliases[i].value, v);
				save_alias(n, v);
				return (1);
			}
		}
		_strcpy(aliases[alias_count].name, n);
		_strcpy(aliases[alias_count].value, v);
		alias_count++;
		save_alias(n, v);
		return (1);
	} else if (alias_count >= MAX_ALIASES)
	{
		printf("Maximum number of aliases exceeded.\n");
		return (0);
	}
}

/**
 * delete_alias - delete alias
 * @alias_name: name
 * @aliases: list
 * @alias_count: parameter
 * Return: result
 */
int delete_alias(const char *alias_name, int alias_count, Alias aliases)
{
	for (int i = 0; i < alias_count; i++)
	{
		if (strcmp(aliases[i].name, alias_name) == 0)
		{
			for (int j = i; j < alias_count - 1; j++)
			{
				strcpy(aliases[j].name, aliases[j + 1].name);
				strcpy(aliases[j].value, aliases[j + 1].value);
			}
			alias_count--;
			char env_name[MAX_ALIAS_NAME_LENGTH + 7] = "ALIAS_";

			strcat(env_name, alias_name);
			unsetenv(env_name);
			return (1);
		}
	}
	printf("Alias not found.\n");
	return (0);
}

/**
 * unset_alias - unset alias
 * @alias_name: name
 * @aliases: list
 * @alias_count: parameter
 * Return: result
 */
int unset_alias(const char *alias_name, int alias_count, Alias aliases)
{
	for (int i = 0; i < alias_count; i++)
	{
		if (strcmp(aliases[i].name, alias_name) == 0)
		{
			for (int j = i; j < alias_count - 1; j++)
			{
				aliases[j] = aliases[j + 1];
			}
			alias_count--;
			char env_name[MAX_ALIAS_NAME_LENGTH + 7] = "ALIAS_";

			_strcat(env_name, alias_name);
			const char *name = env_name;
			int o = _unsetenv(name);

			if (o >= 0)
				printf("Alias '%s' has been removed.\n", alias_name);
			return (1);
		}
	}
	printf("Alias '%s' not found.\n", alias_name);
	return (0);
}
/**
 * insert_existing_aliases - fill the list alias with aliases from env
 * @aliases: list
 * @alias_count: parameter
 */
void insert_existing_aliases(int alias_count, Alias aliases)
{
	alias_count = 0;

	for (int i = 0; environ[i] != NULL; i++)
	{
		char *env_var = environ[i];

		if (strncmp(env_var, "ALIAS_", 6) == 0)
		{
			char *equals_sign = strchr(env_var, '=');

			if (equals_sign != NULL)
			{
				*equals_sign = '\0';
				char *alias_name = env_var + 6;
				char *alias_value = equals_sign + 1;

				if (alias_count < MAX_ALIASES)
				{
					strncpy(aliases[alias_count].name, alias_name, MAX_ALIAS_NAME_LENGTH);
					strncpy(aliases[alias_count].value, alias_value, MAX_ALIAS_VALUE_LENGTH);
					alias_count++;
				} else
				{
					printf("Maximum number of aliases exceeded.\n");
					break;
				}
			}
		}
	}
}
