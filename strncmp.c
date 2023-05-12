#include "shell.h"
/**
 * _strncmp - Compare two strings up to a given number of bytes.
 * @s1:vparameter
 * @s2: paremeter
 * @n: number of bytes
 * Return: result
 */
 /* BY CHARIFA MASBAHI & NORA JEOUT*/
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index = 0;

	while (index < n)
	{
		if (s1[index] != s2[index])
			return ((s1[index] < s2[index]) ? -1 : 1);
		else if (s1[index] == '\0')
			return (0);
		index++;
	}
	return (0);
}
