#include "shell.h"
/**
 * display_aliases - func that display the all aliases
 * Return: void
 */
void display_aliases(void)
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
 * Return: result
 */
const char *get_alias(const char *alias_name)
{
	for (int i = 0; i < alias_count; i++)
	{
		if (strcmp(aliases[i].name, alias_name) == 0)
		{
			return (aliases[i].value);
		}
	}
	return (NULL);
}

/**
 * exec_alias - execute alias commands
 * @args: array of words
 * Return: nothing
 */
void exec_alias(char **args)
{
	if (_strcmp(args[0], "alias") == 0)
	{
		if (args[1] == NULL)
		{
			display_aliases();
		} else
		{
			int i = 1;

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
					if (add_alias(alias_name, alias_value) == 0)
					{
						return;
					}
				} else
				{
					const char *alias_name = args[i];
					const char *alias_value = get_alias(alias_name);

					if (alias_value != NULL)
					{
						printf("%s=%s\n", alias_name, alias_value);
					} else
					{
						printf("Alias '%s' not found.\n", alias_name);
					}
				}
				i++;
			}
		}
	} else if (_strcmp(args[0], "unalias") == 0)
	{
		int i = 1;

		while (args[i] != NULL)
		{
			const char *alias_name = args[i];

			if (!unset_alias(alias_name))
			{
				printf("Alias '%s' not found.\n", alias_name);
			}
			i++;
		}
	}
}