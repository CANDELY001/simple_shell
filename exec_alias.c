#include "shell.h"

/**
 * exec_alias_helper - execute alias commands helper
 * @args: array of words
 * @aliases: list
 * @alias_count: parameter
 */
void exec_alias_helper(char **args, int alias_count, Alias aliases)
{
	int i = 1;

	while (args[i] != NULL)
	{
		const char *alias_name = args[i];

		if (!unset_alias(alias_name, alias_count, aliases))
			printf("Alias '%s' not found.\n", alias_name);
		i++;
	}
}
/**
 * exec_alias - execute alias commands
 * @args: array of words
 */
void exec_alias(char **args)
{
	Alias aliases[MAX_ALIASES];
	int alias_count = 0, i = 1;

	if (_strcmp(args[0], "alias") == 0)
	{
		if (args[1] == NULL)
			display_aliases();
		else
		{
			while (args[i] != NULL)
			{
				const char *arg = args[i];
				const char *equals_sign = strchr(arg, '=');

				if (equals_sign)
				{
					char alias_name[MAX_ALIAS_NAME_LENGTH];
					char alias_value[MAX_ALIAS_VALUE_LENGTH];

					strncpy(alias_name, arg, equals_sign - arg);
					alias_name[equals_sign - arg] = '\0';
					strcpy(alias_value, equals_sign + 1);
					if (add_alias(alias_name, alias_value, alias_count, aliases) == 0)
						return;
				} else
				{
					const char *alias_name = args[i];
					const char *alias_value = get_alias(alias_name, alias_count, aliases);

					if (alias_value != NULL)
						printf("%s=%s\n", alias_name, alias_value);
					else
						printf("Alias '%s' not found.\n", alias_name);
				}
				i++;
			}
		}
	} else if (_strcmp(args[0], "unalias") == 0)
		exec_alias_helper(args);
}
/**
 * display_aliases - func that display the all aliases
 * @aliases: list
 * @alias_count: parameter
 */
void display_aliases(int alias_count, Alias aliases)
{
	if (alias_count > 0)
	{
		int i;

		printf("Current aliases:\n");
		for (i = 0; i < alias_count; i++)
		{
			printf("%s=%s\n", aliases[i].name, aliases[i].value);
		}
	} else
	{
		printf("No aliases defined.\n");
	}
}
/**
 * get_alias - get the value of a given alias
 * @alias_name: alias name
 * @aliases: list
 * @alias_count: parameter
 * Return: result
 */
const char *get_alias(const char *alias_name, int alias_count, Alias aliases)
{
	for (int i = 0; i < alias_count; i++)
	{
		if (_strcmp(aliases[i].name, alias_name) == 0)
		{
			return (aliases[i].value);
		}
	}
	return (NULL);
}
