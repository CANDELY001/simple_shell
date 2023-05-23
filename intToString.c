#include "shell.h"

/**
 * intToString - convert int to a str
 * @n: integer
 * Return: string
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
char *intToString(int n)
{
	int negative = 0, c = 0, tmp, i = 0, j = 0;
	char *s;

	if (n < 0)
	{
		negative = 1;
		n *= -1;
		c++;
	}
	tmp = n;
	while (tmp > 0)
	{
		c++;
		tmp /= 10;
	}
	s = (char *) malloc(sizeof(char) * (c + 1));
	do {
		s[i++] = (n % 10) + '0';
		n /= 10;
	} while (n);
	if (negative)
	{
		s[i++] = '-';
	}
	j = i - 1;
	i = 0;
	while (i < j)
	{
		char tmp = s[i];

		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
	s[c] = '\0';
	return (s);
}
