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
#define MAX_ALIASES 100
#define MAX_ALIAS_NAME_LENGTH 50
#define MAX_ALIAS_VALUE_LENGTH 100
#define MAX_ALIAS_COUNT 1024
#define BUFFER_SIZE 1024
#define EXIT_CODE_STR_SIZE 16
#define PID_STR_SIZE 16
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64

extern char **environ;

/**
 * struct t_alias - Represents an alias with a name and value.
 * @name: alias name
 * @value: alias value
 */
typedef struct t_alias
{
	char name[MAX_ALIAS_NAME_LENGTH];
	char value[MAX_ALIAS_VALUE_LENGTH];
} Alias;

/** Global aliases array and count*/
Alias aliases[MAX_ALIASES];
int alias_count = 0;

char *read_input();

/*Useful functions*/
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *s);
char *intToString(int n);
int _isdigit(int c);
int _atoi(const char *s);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
int is_valid(char *s);
void free_words(char **s, int n);
char **split_string(char *s, const char *separator, int *n);
char *_strstr(const char *haystack, const char *needle);
char *_strncpy(char *dest, char *src, size_t n);

/* File management */
int check_file(const char *path);
char *get_dir_p(const char *path, const char *cmd);
char *get_p_cp();

/**Handle Files*/
void run_commands_from_file(char *filename);
void exec_file(char *cmd);
int tokenize_command(char *cmd, char *args[]);

/*forking*/
int exec_forking(char **arr_words, char *prompt, char *name, int cnt, int n);
char *get_path(const char *cmd);
void cmd_execve(char *cmd, char **arr_words);
void wait_kid_process(pid_t pid, int *status);
void exec_binLs(char **arr_words);

/*Getline*/
ssize_t _getline(char **storage_ptr, size_t *size_storage, FILE *stream);
int read_from_input(char *read_buf);
void *_realloc(void *old_ptr, size_t size);
void edit_buff(char **buff_ptr, size_t *buff_size, char *buffer, size_t idx);

/**handle exit , setenv, unsetenv, cd*/
int handle_multi_cmds(char **arr, char *ppt, char *name, int cnt, int n);
void handle_env(void);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void handle_cd(char **arr_words);

/**handle alias*/
void insert_existing_aliases(void);
int save_alias(const char *alias_name, const char *alias_value);
int add_alias(const char *alias_name, const char *alias_value);
int delete_alias(const char *alias_name);
int unset_alias(const char *alias_name);
void exec_alias(char **args);
void display_aliases(void);
const char *get_alias(const char *alias_name);

/**Handle $$/ $?*/
void replace_variable(char **arr_words, const char *var, const char *value);

/*CD helper functions*/
char *env_vars(const char *env_name, char **env_ptr);
void isError(const char *msg);
char *get_dir(const char *init_p);
char *handle_cwd();
void switch_current_dir(const char *dir);

/*execute multiple commands*/
int exec_multi_cmds(char *prompt, char *sh_name, int cnt);
void p_the_err(char *cnt, char *sh_name, char *cmd, char *msg);
void handle_signal(int sig);
void handle_exit_status(char **arr, char *ppt, char *name, int c, int n);
void ex_err(char **arr_words, int cnt, char *sh_name);

#endif
