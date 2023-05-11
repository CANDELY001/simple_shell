#include "shell.h"

/**
 * intToString - int to a str
 * @num: integer
 * Return: string
 */
 /* BY CHARIFA MASBAHI & NORA JEOUT*/
char *intToString(int num)
{
	int neg_num = 0, digCntr = 0, tmp, i = 0, j = 0;
	char *str;

	if (num < 0)
	{
		neg_num = 1;
		num *= -1;
		digCntr++;
	}
	tmp = num;
	while (tmp > 0)
	{
		digCntr++;
		tmp /= 10;
	}
	str = (char *) malloc(sizeof(char) * (digCntr + 1));
	do {
		str[i++] = (num % 10) + '0';
		num /= 10;
	} while (num);
	if (neg_num)
	{
		str[i++] = '-';
	}
	j = i - 1;
	i = 0;
	while (i < j)
	{
		char tmp = str[i];

		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	str[digCntr] = '\0';
	return (str);
}
