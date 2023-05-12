#include "shell.h"
/**
 * is_valid - check if word valid
 * @s: word
 * Return: 1 if valid 0 no
*/
/* BY CHARIFA MASBAHI & NORA JEOUT*/
int is_valid(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (!isalnum(s[i]) && s[i] != '-' && s[i] != '_' && s[i] != '.')
			return (0);
		i++;
	}
	return (1);
}
