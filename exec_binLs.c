#include "shell.h"
#include <sys/wait.h>

/**
 * exec_binLs - handle /bin/ls
 * @arr_words: arr containing commands
 * Return: void
 */
void exec_binLs(char **arr_words)
{
    pid_t pid;
    int curr_status;

    pid = fork();
    if (pid == 0)
    {
        cmd_execve("/bin/ls", arr_words);
        perror("Error executing command\n");
        exit(2);
    }
    else if (pid < 0)
    {
        perror("Error forking");
        return;
    }

    waitpid(pid, &curr_status, 0);

    if (WIFEXITED(curr_status))
        exit(WEXITSTATUS(curr_status));
    else if (WIFSIGNALED(curr_status))
        exit(128 + WTERMSIG(curr_status));
    else
        exit(1);
}
