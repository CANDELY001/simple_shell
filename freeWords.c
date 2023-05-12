#include "shell.h"

/**
 * free_words - Frees a list of words.
 * @s: Pointer to an array of strings.
 * @n: Number of words in the array.
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
void free_words(char **s, int n)
{
	int i;

	if (!s)
		return;
	while (i < n)
	{
		if (s[i])
		{
			free(s[i]);
			s[i] = NULL;
		}
		i++;
	}
	free(s);
}
