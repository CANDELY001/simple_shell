#include "shell.h"
/**
 * _isdigit - function that checks for a digit
 * @c: parameter
 * Return:1 (Success)
 */
 /* BY CHARIFA MASBAHI & NORA JEOUT*/
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
