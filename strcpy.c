#include "shell.h"

/**
 * _strcpy - copies a src to dest
 * @dest: parameter
 * @src: paraemeter
 * Return: result
*/
/* BY CHARIFA MASBAHI & NORA JEOUT*/

char *_strcpy(char *dest, const char *src)
{
	char *s = dest;

	while (*src != '\0')
	{
		*s++ = *src++;
	}
	*s = '\0';
	return (dest);
}
