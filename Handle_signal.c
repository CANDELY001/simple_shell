#include "shell.h"
/**
 * handle_signal - handle signal
 * @sig: signal
 * Return: void.
 */
void handle_signal(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n#cisfun$ ", 4);
}
