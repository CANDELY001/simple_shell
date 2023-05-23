#include "shell.h"
/**
 * handle_env - Prints the env variables.
 * Return: void
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
void handle_env(void)
{
	char **env_pointer = environ;

	while (*env_pointer)
	{
		printf("%s\n", *env_pointer);
		env_pointer++;
	}
}
