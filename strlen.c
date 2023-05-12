#include "shell.h"

/**
 * _strlen - returns string length
 * @s: parameter
 * Return: result
*/
/* BY CHARIFA MASBAHI & NORA JEOUT*/

size_t _strlen(const char *s)
{
	size_t len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
