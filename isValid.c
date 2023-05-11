#include "shell.h"
/**
 * is_valid - check if workd valid
 * @str: word
 * Return: 1 if valid 0 no
*/
/* BY CHARIFA MASBAHI & NORA JEOUT*/
int is_valid(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (!isalnum(str[i]) && str[i] != '-' && str[i] != '_' && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}
