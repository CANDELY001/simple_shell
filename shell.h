#ifndef SHELL_H
#define SHELL_H

/*Libraries*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <ctype.h>
#include <errno.h>

#define STORAGE_SIZE 1024
extern char **environ;

char *read_input();

/*Useful functions*/

char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *str);
char *intToString(int num);
int _isdigit(int c);
int _atoi(const char *s);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *s);
int _strncmp(const char *st1, const char *st2, size_t n);
int is_valid(char *str);
void free_words(char **words, int n);
char **split_string(char *str, const char *str_separator, int *num_of_words);

#endif
