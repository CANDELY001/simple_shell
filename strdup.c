#include "shell.h"

/**
 * _strdup - Duplicates a string
 * @s: string
 * Return: result
 */
 /* BY CHARIFA MASBAHI & NORA JEOUT*/
char *_strdup(const char *s)
{
	size_t len = _strlen(s), i;
	char *duplicat = malloc(len + 1);

	if (duplicat)
	{
		for (i = 0; i < len; i++)
			duplicat[i] = s[i];
		duplicat[len] = '\0';
	}
	return (duplicat);
}
