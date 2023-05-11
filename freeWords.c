#include "shell.h"

/**
 * free_words - Frees a list of words.
 * @words: Pointer to an array of strings.
 * @n: Number of words in the array.
 * This function frees each individual string in the array using the
 * free() function and finally frees the array itself using free().
 */
  /* BY CHARIFA MASBAHI & NORA JEOUT*/
void free_words(char **words, int n)
{
	int i;

	if (words == NULL)
		return;
	for (i = 0; i < n; i++)
	{
		if (words[i] != NULL)
		{
			free(words[i]);
			words[i] = NULL;
		}
	}
	free(words);
}
