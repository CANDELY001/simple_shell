#include "shell.h"

/**
 * split_string - splits a string into an array of words
 * @s: the str to be splited
 * @separator: the delimeter
 * @n: number of words in the str
 * Return: the array of string or NULL
*/
/* BY CHARIFA MASBAHI & NORA JEOUT*/
char **split_string(char *s, const char *separator, int *n)
{
	char *s_copy = NULL, *word = NULL, **words;
	int i;

	s_copy = malloc(sizeof(char) * _strlen(s) + 1);
	if (!s_copy)
	{
		perror("Allocation Failed !");
		return (NULL);
	}
	_strcpy(s_copy, s);
	*n = 0;
	word = strtok(s, separator);
	while (word)
	{
		(*n)++;
		word = strtok(NULL, separator);
	}
	words = malloc(sizeof(char *) * (*n + 1));
	if (words == NULL)
	{
		perror("Allocation Failed !");
		return (NULL);
	}
	word = strtok(s_copy, separator);
	for (i = 0; word != NULL; i++)
	{
		words[i] = malloc(sizeof(char) * _strlen(word) + 1);
		if (words[i] == NULL)
		{
			perror("Allocation Failed !");
			return (NULL);
		}
		_strcpy(words[i], word);
		word = strtok(NULL, separator);
	}
	words[i] = NULL;
	free(s_copy);
	return (words);
}
