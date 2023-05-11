#include "shell.h"

/**
 * _memcpy - copies mem like c memcpy
 * @dest: parameter
 * @src: parameter
 * @n: tparameter
 * Return: void
*/
/* BY CHARIFA MASBAHI & NORA JEOUT*/
void *_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *destt = dest;
	const unsigned char *srcc = src;
	size_t idx = 0;

	while (idx < n)
	{
		destt[idx] = srcc[idx];
		idx++;
	}
	return (dest);
}
