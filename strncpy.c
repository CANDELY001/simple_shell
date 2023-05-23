#include "shell.h"
/**
 * *_strncpy -  a function that copies a string
 * @dest: a parameter
 * @src: a parameter
 * @n: a parameter
 * Return: result
 */
/*BY CHARIFA MASBAHI & NORA JEOUT*/
char *_strncpy(char *dest, char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
