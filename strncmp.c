#include "shell.h"
/**
 * _strncmp - Compare two strings up to a given number of bytes.
 * @st1:vparameter
 * @st2: paremeter
 * @n: number of bytes
 * Return: result
 */
 /* BY CHARIFA MASBAHI & NORA JEOUT*/
int _strncmp(const char *st1, const char *st2, size_t n)
{
	size_t idx = 0;

	while (idx < n)
	{
		if (st1[idx] != st2[idx])
			return ((st1[idx] < st2[idx]) ? -1 : 1);
		else if (st1[idx] == '\0')
			return (0);
		idx++;
	}
	return (0);
}
