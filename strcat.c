#include "shell.h"
/**
 * *_strcat -  a function that concatenates two strings
 * @dest: a parameter
 * @src: a parameter
 * Return: result
 */
 /* BY CHARIFA MASBAHI & NORA JEOUT*/
char *_strcat(char *dest, const char *src)
{
	int len = 0;
	int len2 = 0, i;

	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[len2] != '\0')
	{
		len2++;
	}
	for (i = 0; i < len2; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
	return (dest);
}
